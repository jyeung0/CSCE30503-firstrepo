#include <stdio.h>

#define SIZE 64


int main(){
    char buffer[SIZE];

    fgets(buffer,SIZE-1,stdin);
    printf("Input: %s\n",buffer);

    return 0;
}