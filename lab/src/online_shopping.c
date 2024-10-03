#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int choice,num;
char *product[3] = {
    "shirt\n",
    "sticker\n",
    "tissue\n"
};

void buy(){
    printf("We have 3 products:\n");
    for(int i=0; i<3; i++){
        printf("%d. %s", i+1, product[i]);
    }
    printf("Which one do you want to buy? ");
    scanf("%d", &choice);
    printf("You have bought %s\n", product[choice-1]);
    printf("How many do you want to buy? ");
    scanf("%d", &num);
    return;
}

char address[0x20];
int main(){
    setvbuf(stdout, 0, _IONBF, 0);
    setvbuf(stdin, 0, _IONBF, 0);
    printf("This is HackerSir!\n");
    printf("Welcome to the shop!\n");
    printf("1. Buy\n");
    printf("2. Exit\n");
    printf("Your choice: ");
    scanf("%d", &choice);
    if(choice==1){
        buy();
        printf("Please leave your address: ");
        scanf("%s", address);
        printf(address);
    }else{
        printf("Goodbye!\n");
        exit(0);
    }
    char last[0x10];
    printf("\nleave your last message to our club: ");
    read(0, last, 0x30);
    return 0;
}

