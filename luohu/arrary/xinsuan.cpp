#include "stdio.h"
#include "iostream"

int main(){
    int value[10001]={0},a[101]={0},n,count=0;
    scanf("%d",&n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d",&a[i]),value[a[i]]++;
    }
    for (int i = 1; i <=n ; ++i) {
        for (int j = i+1; j <=n; ++j) {
            if (value[a[i]+a[j]]==1){count++;value[a[i]+a[j]]=2;}
        }
    }
    std::cout<<count;
    return 0;
}