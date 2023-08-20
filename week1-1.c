// Print sum of 2 times
#include <stdio.h>

struct time{
    int h,m,s;
} t[3];
void main(){
    printf("Enter time 1: H M S: ");
    scanf("%d %d %d",&t[0].h,&t[0].m,&t[0].s);
    printf("Enter time 2: H M S: ");
    scanf("%d %d %d",&t[1].h,&t[1].m,&t[1].s);
    if (t[0].s+t[1].s>60){
        t[2].m=1;
        t[2].s=-60;
    }
    t[2].s+=t[0].s+t[1].s;
    if (t[0].m+t[1].m>60){
        t[2].h=1;
        t[2].m-=60;
    }
    t[2].m+=t[0].m+t[1].m;
    t[2].h+=t[0].h+t[1].h;
    printf("Summed time: %d %d %d",t[2].h,t[2].m,t[2].s);
}