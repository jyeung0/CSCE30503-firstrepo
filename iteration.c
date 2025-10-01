#include <stdio.h>

#define SIZE 5

int main(){
    int x[] = {1,2,3,4,5};
    int i;
    for(int i =0; i < SIZE; i++){
        printf("[%d]",x[i]);
    }
    printf("\n");
    int k;
    char y[] = "Hello";
    for(int k = 0; k != '\0'; k++){
        printf("%c",y[k]);
    }

    

    return 0;
}