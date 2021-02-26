#include "stdio.h"
#include "iostream"

int main(){
    int s1,s2,s3,value[81]={0},max_sum=0;
    std::cin>>s1>>s2>>s3;
    for (int i = 1; i <=s1 ; ++i) {
        for (int j = 1; j <=s2 ; ++j) {
            for (int k =1; k <=s3; ++k) {
                value[i+j+k]++;
//                printf("%d %d %d -> %d\n",i,j,k,value[i+j+k]);
            }
        }
    }
    int a=0;
    for (int i =3; i <=s1+s2+s3 ; ++i) {
        if (value[i]>a){a=value[i],max_sum=i;}
    }
    printf("%d",max_sum);
    return 0;
}