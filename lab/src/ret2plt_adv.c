#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void pop_rdi(){
    __asm__("pop %rdi; ret;");
}

int main(){
    setvbuf(stdout, 0, 2, 0);
    setvbuf(stdin, 0, 2, 0);
    setvbuf(stderr, 0, 2, 0);
    char message[0x10];
    puts("Welcome to challenge!");
    puts("Leave a message: ");
    read(0, message, 0x100);
    return 0;
}

