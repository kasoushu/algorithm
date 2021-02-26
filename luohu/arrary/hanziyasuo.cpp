#include "stdio.h"
#include "iostream"


int main(){
    int n,k=0,num=0,x=0;
    std::cin>>n;
    for (int i = 1; i <=n*n ;) {
        std::cin>>num;
        if (k%2==0){
            for (int j = 1; j <=num ; ++j) {
                printf("0");
                x++;
                if(x%n==0) printf("\n");
            }
            i+=num;
        } else{
            for (int j = 1; j <=num ; ++j) {
                printf("1");
                x++;
                if(x%n==0) printf("\n");
            }
            i+=num;
        }
        k=(k+1)%2;
    }
}