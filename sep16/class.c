#include <stdio.h>
#include <stdlib.h>

int main(){
    int size = 5;
    int index;
    int *numbers;

    numbers = (int *)malloc(size * sizeof(int));

    numbers[0]= 10;
    numbers[1]= 20;
    numbers[2]= 30;
    numbers[3]= 40;
    numbers[4]= 50;

    for(index =0;index<5;index++){
        printf("%d\n",numbers[index]);
    }
    return 0;
}