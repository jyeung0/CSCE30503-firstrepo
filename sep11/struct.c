#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 64

struct student{
    int id;
    char first[SIZE];
    char last[SIZE];
};
typedef struct student Student;

void showStudent(struct student stud);
void showStudentRef(struct student *stud);
int main(){
    Student student1;
   
    student1.id=1001;
    strcpy(student1.last,"Smith");
    strcpy(student1.first,"Joe");

    Student *student2;
    printf("%s\n",student2->first);   ///new blows up file
    student2 = malloc(sizeof(struct student));
    student2->id=1002;
    strcpy(student2->last,"Jones");
    //strcpy(student2->first,"Jack");


    showStudent(student1);
    showStudentRef(&student1);
    showStudentRef(student2);
    free(student2);  //new
    return 0;
}

void showStudent(struct student stud){
    printf("id: %d\n", stud.id);
    printf("First: %s\n",stud.first);
    printf("Last: %s\n", stud.last);
    printf("Size: %d\n",sizeof(stud));
}

void showStudentRef(struct student *stud){
    printf("id: %d\n", stud->id);
    printf("First: %s\n",stud->first);
    printf("Last: %s\n", stud->last);
    printf("Size: %d\n",sizeof(stud));
}