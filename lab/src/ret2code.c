#include<stdio.h>

void shell(){
    system("/bin/sh");
}

int main(){
    setvbuf(stdout, 0, 2, 0);
    setvbuf(stdin, 0, 2, 0);
    setvbuf(stderr, 0, 2, 0);
    char b[10];
    puts("Send me a message: ");
    gets(b);
    return 0;
}
