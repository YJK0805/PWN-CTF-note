#include<stdio.h>
#include<stdlib.h>

int backdoor(const char *arg){
    system("/bin/sh");
}

long long value[4];

int main(){
    setvbuf(stdin, 0, 2, 0);
    setvbuf(stdout, 0, 2, 0);
    setvbuf(stderr, 0, 2, 0);
    long long index;
    for(int i = 0; i < 4; i++){
        puts("Enter a index to store a value: ");
        scanf("%lld", &index);
        puts("Enter a value: ");
        scanf("%lld", &value[index]);
    }
    if(value[0] != 123){
        puts("CHECK FAILED\n");
        exit(0);
    }
    if(value[1] != 456){
        puts("CHECK FAILED\n");
        exit(0);
    }
    if(value[2] != 789){
        puts("CHECK FAILED\n");
        exit(0);
    }
    if(value[3] != 101112){
        puts("CHECK FAILED\n");
        exit(0);
    }
    puts("CHECK PASSED\n");
    return 0;
}
