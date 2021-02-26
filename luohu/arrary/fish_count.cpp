#include "stdio.h"


int main(){
    int a[101]={0};
    for (int i = 1; i <=100 ; ++i) {
        int k;
        scanf("%d",&k);
        if (k==0){
            break;
        }
        a[i]=k;
    }
    for (int i = 100; i >=1; --i) {
        if (a[i]!=0){
            printf("%d ",a[i]);
        }
    }
    return 0;
}