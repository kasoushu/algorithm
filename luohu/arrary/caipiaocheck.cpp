#include "stdio.h"
#include "iostream"
int  main(){
    int haoma[34]={0},reward[8]={0},a,count,n;
    scanf("%d",&n);
    for (int i = 1; i <=7 ; ++i) {
        scanf("%d",&a),haoma[a]++;
    }
    for (int i = 1; i <=n; ++i) {
        count=0;
        for (int j = 1; j <=7 ; ++j) {
            scanf("%d",&a);
            if(haoma[a]==1)  count++;
        }
        reward[count]++;
    }
    for (int i = 7; i >=1 ; i--)std::cout<<reward[i]<<' ';
    return 0;
}