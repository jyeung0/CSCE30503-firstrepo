#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

int loadArray(char *name, char *array[]);
int showArray(char *x[],int size);

int main(){
    char *array[SIZE];
    int len = loadArray("strings.txt", array);
    showArray(array,len);
    return 0;
}

int loadArray(char* name, char *array[]){
    FILE *fp;
    fp = fopen(name,"r");
    if(fp == NULL){
        exit(1);
    }
    char buffer[SIZE];
    int len=0;
    char *str;
   

    while((fgets(buffer,SIZE - 1,fp)) != NULL ){
        if(buffer[strlen(buffer)-1] == '\n'){
        buffer[strlen(buffer)-1 ] ='\0';
    }
        str = malloc(strlen(buffer)+1);
        strcpy(str,buffer);
        array[len]=str;
        len++;
    }
  
    fclose(fp);
    return len;
}
int showArray(char *x[],int size){
     for(int i = 0;i < size;i++){
      
        printf("[%d]: %s\n",i,x[i]);
     }
}