#include "stdio.h"
#include "algorithm"
#include "iostream"
using namespace std;

int main(int argc, char const *argv[])
{
    int a[2000001];
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++) cin>>a[i];
    sort(a,a+m);
    for(int i=0;i<m;i++) cout<<a[i]<<' ';
    return 0;
}
