#include<stdio.h>

int main(){
    setvbuf(stdout, 0, 2, 0);
    setvbuf(stdin, 0, 2, 0);
    setvbuf(stderr, 0, 2, 0);
    char buf[0x20];
    printf("Give me your message: ");
    read(0, buf, 0x200);
    return 0;
}

