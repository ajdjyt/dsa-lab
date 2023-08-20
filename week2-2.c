#include <stdio.h>
struct stud{
    char name[50];
    int rno;
    float marks;
};
void main(){
    int n;
    printf("Enter number of students: ");
    scanf("%d",&n);
    struct stud *ptr,studs[n];
    ptr=studs;
    for(int i=0;i<n;i++){
        printf("Student %i\n",i+1);
        printf("Enter RollNo Name Marks: ");
        scanf("%d %s %f",&(ptr+i)->rno,(ptr+i)->name,&(ptr+i)->marks);
    }
    printf("Student details\n");
    for(int i=0;i<n;i++){
        printf("RollNo: %d, Name: %s, Marks: %.2f\n",(ptr+i)->rno,(ptr+i)->name,(ptr+i)->marks);
    }
}