// Input emp data and print using pointers
#include <stdio.h>

struct emp{
    char name[50];
    int id;
    float sal;
} *ptr,emps;
void main(){
    ptr=&emps;
    printf("Enter Name: ");
    scanf("%s",ptr->name);
    printf("Enter ID: ");
    scanf("%d",&ptr->id);
    printf("Enter salary: ");
    scanf("%f",&ptr->sal);
    printf("Employee details\n");
    printf("ID: %d, Name: %s, Salary: %.2f",ptr->id,ptr->name,ptr->sal);
}