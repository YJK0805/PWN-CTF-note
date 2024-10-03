#include<stdio.h>
#include<stdlib.h>

struct Note{
    void (*printnote_content)();
    char *content;
};

struct Note *noteList[10];
int noteCount = 0;

void printnote_content(struct Note *this){
    printf("%s\n", this->content);
}

void add_note(){
    int i,size;
    if(noteCount >= 10){
        printf("No more space for new note\n");
        return;
    }
    for(i=0; i < 10; i++){
        if(noteList[i] == NULL){
            noteList[i] = (struct Note *)malloc(sizeof(struct Note));
            if(noteList[i] == NULL){
                printf("Memory allocation failed\n");
                exit(1);
            }
            noteList[i]->printnote_content = printnote_content;
            printf("Enter the size of the note: ");
            scanf("%d", &size);
            noteList[i]->content = (char *)malloc(size);
            if(noteList[i]->content == NULL){
                printf("Memory allocation failed\n");
                exit(1);
            }
            printf("Enter the content of the note: ");
            read(0, noteList[i]->content, size);
            noteCount++;
            break;
        }
    }
}

void delete_note(){
    int index;
    printf("Enter the index of the note: ");
    scanf("%d", &index);
    if(index < 0 || index >= noteCount){
        printf("Invalid index\n");
        exit(1);
    }
    if(noteList[index] != NULL){
        free(noteList[index]->content);
        free(noteList[index]);
        printf("Note deleted\n");
    }
}

void print_note(){
    int index;
    printf("Enter the index of the note: ");
    scanf("%d", &index);
    if(index < 0 || index >= noteCount){
        printf("Invalid index\n");
        exit(1);
    }
    if(noteList[index] != NULL){
        noteList[index]->printnote_content(noteList[index]);
    }
}

void backdoor(){
    system("/bin/sh");
}

void menu(){
    printf("1. Add note\n");
    printf("2. Delete note\n");
    printf("3. Print note\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

int main(){
    setvbuf(stdout, 0, 2, 0);
    setvbuf(stdin, 0, 2, 0);
    setvbuf(stderr, 0, 2, 0);
    while(1){
        menu();
        int choice;
        scanf("%d", &choice);
        switch(choice){
            case 1:
                add_note();
                break;
            case 2:
                delete_note();
                break;
            case 3:
                print_note();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}
