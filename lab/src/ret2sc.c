#include<stdio.h>
#include <unistd.h>
#include <sys/mman.h>
char shellcode[0x100];
int main(){
    setvbuf(stdout, 0, _IONBF, 0);
    setvbuf(stdin, 0, _IONBF, 0);
    setvbuf(stderr, 0, _IONBF, 0);
    unsigned long addr = (unsigned long)&shellcode & ~0xfff;
    mprotect((void *)addr, 0x1000, PROT_EXEC | PROT_READ | PROT_WRITE);
    printf("Give me shellcode: ");
    read(0, shellcode, 0x100);
    printf("Overflow me: ");
    char buffer[0x10];
    gets(buffer);
    printf("Bye!\n");
    return 0;
}
