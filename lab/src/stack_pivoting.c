#include<stdio.h>
#include<stdlib.h>

char name[0x100];

int main(){
    setvbuf(stdout, 0, 2, 0);
    setvbuf(stdin, 0, 2, 0);
    setvbuf(stderr, 0, 2, 0);
    char message[0x10];
    puts("Welcome to challenge!");
    puts("What's your name?");
    read(0, name, 0x100);
    puts("Leave a message: ");
    read(0, message, 0x20);
    return 0;
}

