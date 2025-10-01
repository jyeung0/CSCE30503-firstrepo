#include <stdio.h>

#define SIZE 5

int main(){
    int numbers[] = {10,20,30,40,50};
    char str[]="Hello";

    int index;

    for(index=0;index<SIZE;index++){
        printf("[%d]: %d\n", index,numbers[index]);
    }
    printf("\n\n");
    //character
    for(index=0;index<SIZE;index++){
        printf("[%d]: %c\n", index,str[index]);
    }

    return 0;
}