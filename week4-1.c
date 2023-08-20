#define n 100
#include <stdio.h>
#include <stdlib.h>

void show(int* list,int size){
    printf("[");
    for(int i=0;i<size;i++){
        printf("%d",list[i]);
        if(i+1!=size){
            printf(",");
        }
    }
    printf("]\n");
}
void add(int* list, int* size,int ele){
    if((*size)>=n){
        printf("Cannot add\n");
        return;
    }
    list[*size]=ele;
    (*size)++;
    show(list,*size);
}
void rm(int* list,int* size,int ele){
    if(ele>=(*size)){
        printf("Index not in list\n");
        return;
    }
    list[ele]=0;
    for(int i=ele;i<*size-1;i++){
        list[i]=list[i+1];
    }
    (*size)--;
    show(list,*size);
}
void main(){
    int list[n],size=0,ans,ele;
    while(1){
        printf("0.Quit\n");
        printf("1.Display list\n");
        printf("2.Add to list\n");
        printf("3.Remove from list\n");
        printf("Select a choice: ");
        scanf("%d",&ans);
        switch(ans){
            case 0:
                exit(0);
            case 1:
                show(list,size);
                break;
            case 2:
                printf("Enter element: ");
                scanf("%d",&ele);
                add(list,&size,ele);
                break;
            case 3:
                show(list,size);
                printf("Enter element: ");
                scanf("%d",&ele);
                rm(list,&size,ele);
                break;
            default:
                printf("Invalid choice\n");
        }
    }
}