#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>
#include "seccomp-bpf.h"

void apply_seccomp() {
    struct sock_filter filter[] = {
        VALIDATE_ARCHITECTURE,
        EXAMINE_SYSCALL,
        ALLOW_SYSCALL(read),
        ALLOW_SYSCALL(write),
        ALLOW_SYSCALL(open),
        KILL_PROCESS,
    };

    struct sock_fprog prog = {
        .len = (unsigned short)(sizeof(filter) / sizeof(struct sock_filter)),
        .filter = filter,
    };

    if (prctl(PR_SET_NO_NEW_PRIVS, 1, 0, 0, 0)) {
        perror("Seccomp Error");
        exit(1);
    };
    if (prctl(PR_SET_SECCOMP, SECCOMP_MODE_FILTER, &prog)) {
        perror("Seccomp Error");
        exit(1);
    };
}
char shellcode[0x100];
int main() {
    setvbuf(stdin, 0, 2, 0);
    setvbuf(stdout, 0, 2, 0);
    setvbuf(stderr, 0, 2, 0);
    unsigned long addr = (unsigned long)&shellcode & ~0xfff;
    mprotect((void *)addr, 0x1000, PROT_EXEC | PROT_READ | PROT_WRITE);
    apply_seccomp();
    printf("I add new rule to prevent you from using system().\n");
    printf("Give me shellcode: ");
    read(0, shellcode, 0x100);
    printf("Overflow me: ");
    char buffer[0x10];
    gets(buffer);
    printf("Bye!\n");
    return 0;
}
