#include<stdio.h>
#include"iostream"
using namespace std;

int main(){
    int n,s=1,k=2;
    n=10;
    if (n&1) {s=s*k;}
    n=n/2;
    while (n)
    {
        k=k*k;
        if (n&1) s=s*k;
        n=n>>1;
    }
    cout<<s;
    return 0;
}
