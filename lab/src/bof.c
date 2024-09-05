#include<stdio.h>
int main(){
    setvbuf(stdout, 0, 2, 0);
    setvbuf(stdin, 0, 2, 0);
    setvbuf(stderr, 0, 2, 0);
    int a = 10;
    printf("Please input your name: ");
    char b[10];
    gets(b);
    if(a == 0xdeadbeef){
        system("/bin/sh");
    }
    printf("Hello, %s\n", b);
    return 0;
}
