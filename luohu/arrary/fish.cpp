#include "stdio.h"
#include "iostream"
using namespace std;

int main(){
    int a[101],b[101]={0},n;
    cin>>n;
    for (int i = 1; i <= n; ++i) {
        scanf("%d",&a[i]);
    }
    for (int i = 1; i <=n ; ++i) {
        for (int j = i; j >=1 ; --j) {
            if (a[j]<a[i])  b[i]++;
        }
    }
    for (int i= 1; i <=n ; ++i) {
        printf("%d ",b[i]);
    }
    return 0;
}