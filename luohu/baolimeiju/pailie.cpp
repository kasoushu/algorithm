#include "iostream"
#include "stdio.h"

using namespace std;

int jiecheng(int n){
    int k=1;
    for (int i = n; i >1; i--)
    {
        k*=i;
    }
    return k;
}

int main(int argc, char const *argv[])
{
    cout<<jiecheng(5);
    return 0;
}


// int main(int argc, char const *argv[])
// {
//     int a[10005];
//     int n,m;
//     cin>>n>>m;
//     for(int i=0;i<n;i++) {int j;cin>>j;a[j]=i}
//     for(int i=0;i<n;i++) {}
//     return 0;
// }