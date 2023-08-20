// Implement matrix multiplication
#define n 100
#include <stdio.h>
#include <stdlib.h>
void main(){
    int a[n][n],b[n][n],o[n][n],r1,r2,c1,c2,i,j,k;
    printf("Enter r1 c1: ");
    scanf("%d %d",&r1,&c1);
    printf("Enter r2 c2: ");
    scanf("%d %d",&r2,&c2);
    if(c1!=r2){
        printf("Not possible");
        exit(0);
    }
    printf("Enter matrix 1\n");
    for(i=0;i<r1;i++){
        for(j=0;j<c1;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter matrix 2\n");
    for(i=0;i<r1;i++){
        for(j=0;j<c1;j++){
            scanf("%d",&b[i][j]);
        }
    }
    for(i=0;i<r1;i++){
        for(j=0;j<c2;j++){
            for(k=0;k<c1;k++){
                o[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    printf("Resultant matrix\n");
    for(i=0;i<r1;i++){
        for(j=0;j<c2;j++){
            printf("%d ",o[i][j]);
        }
        printf("\n");
    }
}
