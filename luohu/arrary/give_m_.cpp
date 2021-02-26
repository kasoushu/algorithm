#include "iostream"
#include "stdio.h"

using namespace std;

int main(){
    int n,m,value[3001]={0},sum=100000,temp=0;
    std::cin>>n>>m;
    for (int i =1; i <=n; ++i) {
        scanf("%d",&value[i]);
    }
    if (m==0){
        printf("0");
    }
    if (n==m){
        for (int i = 1; i <=n ; ++i) {
            temp+=value[i];
        }
        sum=temp;
    }

    for (int i = 1; i <=n-m+1 ; ++i) {
        temp=0;
        for (int j =0; j <m ; ++j) {
            temp+=value[i+j];
        }
        if (temp<=sum) sum=temp;
    }
    printf("%d",sum);
    return 0;
}