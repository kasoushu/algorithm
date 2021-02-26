#include "stdio.h"
#include "iostream"
// #include "string.h"
// #include "bits/stdc++.h"
using namespace std;
//mo ren liang ge yi yang chang
void cheng(int a[],int b[]){
    int n1=a[0],n2=b[0];
    int c[100000]={0};
    c[0]=a[0]+b[0];
    if(c[0]>500) c[0]=500;
    for (int i =1; i <=c[0]; i++){
        for (int j =1; j <=i; j++){
            c[i]+=a[j]*b[i+1-j];
        if (c[i]>=10){
            c[i+1]+=c[i]/10;
            c[i]=c[i]%10;
    }}
}
    for (int i=0;i<=c[0];i++) a[i]=c[i];
}

int main(int argc, char const *argv[])
{
    int n;
    int a[5000]={1,1,0},b[100000]={1,2,0};
    cin>>n;    
    int k=0.30103*n+1;
    cout<<k<<endl;
    if (n&1) cheng(a,b);
    n>>=1;
    while (n!=0)
    {
        cheng(b,b);
        if(n&1) cheng(a,b);
        n>>=1;
    }
    a[1]-=1;
    for(int i=499;i>=0;i--) {
        cout<<a[i+1];
        if(i%50==0) cout<<endl;
    }
    return 0;
}
