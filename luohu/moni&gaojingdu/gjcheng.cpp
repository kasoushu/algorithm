#include "stdio.h"
#include "iostream"
// #include "string.h"
// #include "bits/stdc++.h"
using namespace std;
//mo ren liang ge yi yang chang
// void cheng(int a[],int b[]){
//     int n1=a[0],n2=b[0];
//     int c[100000]={0};
//     c[0]=a[0]+b[0];
//     for (int i =1; i <=c[0]; i++){
//         for (int j =1; j <=i; j++){
//             c[i]+=a[j]*b[i+1-j];
//         if (c[i]>=10){
//             c[i+1]=c[i]/10;
//             c[i]=c[i]%10;
//     }}
// }
//     for (int i=0;i<=c[0];i++) a[i]=c[i];
// }

int main(int argc, char const *argv[])
{
    string s1,s2;
    int a[100000]={0},b[100000]={0},c[100000]={0};
    cin>>s1>>s2;
    a[0]=s1.size(),b[0]=s2.size();
    int len=a[0]+b[0];
    for (int i=1;i<=a[0];i++) a[i]=s1[a[0]-i]-'0';
    for (int i=1;i<=b[0];i++) b[i]=s2[b[0]-i]-'0';
    for ( int i =1;i<=len;i++)
    for (int j = 1; j <=i; j++){
            c[i]=c[i]+a[j]*b[i+1-j];
            if(c[i]>=10){c[i+1]+=c[i]/10;c[i]=c[i]%10;}
        }
    // for(int i=len;i>0;i--) cout<<c[i];
    while (len>1&&c[len]==0) len--;
    for(int i=len;i>0;i--) cout<<c[i];
    return 0;
}
