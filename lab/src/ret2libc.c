#include<stdio.h>
#include<stdlib.h>

int main(){
    setvbuf(stdout, 0, 2, 0);
    setvbuf(stdin, 0, 2, 0);
    setvbuf(stderr, 0, 2, 0);
    long long num[10] = {0};
    while(1){
        puts("1. Edit number");
        puts("2. Show number");
        puts("3. Exit");
        printf(">> ");
        int choice;
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Index: ");
                int idx;
                scanf("%d", &idx);
                printf("Number: ");
                scanf("%lld", &num[idx]);
                break;
            case 2:
                printf("Index: ");
                int idx2;
                scanf("%d", &idx2);
                printf("Number: %lld\n", num[idx2]);
                break;
            case 3:
                break;
            default:
                puts("Invalid choice");
                break;
        }
    }
    char message[0x20];
    printf("Leave a message: ");
    read(0, message, 0x100);
    return 0;
}

