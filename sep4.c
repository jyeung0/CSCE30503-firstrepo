#include <stdio.h>

#define SIZE 1024

int Strlen(char *str);

int main(){
    char buffer[SIZE] = "Hello Again";

    
    int count = Strlen(buffer);
    printf("%d\n",count);

    return 0;
    
}

int Strlen(char *str){
   
    
    int count = 0;
    
    while(*str !='\0'){
        count++;
        *str++;
    }
    return count;
}