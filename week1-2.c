// Print name,marks and cgpa of multiple people
#include <stdio.h>




struct stud {
    char name[50];
    int marks;
    float cgpa;
} studs[3];
int main(){
    for(int i=0;i<3;i++){
        printf("Student %d\n",i+1);
        printf("Enter name: ");
        scanf("%s",studs[i].name);
        printf("Enter marks: ");
        scanf("%d",&studs[i].marks);
        printf("Enter CGPA: ");
        scanf("%f",&studs[i].cgpa);
    }
    for(int i=0;i<3;i++){
        printf("Name: %s Marks: %d CGPA: %.2f\n",studs[i].name,studs[i].marks,studs[i].cgpa);
    }
    return 0;
}