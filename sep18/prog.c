#include <stdio.h>

#define MAX 100

int main(){
    char *p;
    FILE* file;
    char strings[MAX][250];
    int i = 1;

    file = fopen("Strings.txt","r");
    while((fgets(strings[i],MAX,file)) != NULL){
        i++;
    }
    
    
    fclose(file);

    for(int k = 0; k < i; k++){
        p = strings[k];
        printf("%s",p);
    }
    printf("\n");
   

    return 0;
}