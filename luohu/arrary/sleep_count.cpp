#include <bits/stdc++.h>//华丽地开头
using namespace std;
int js[10],n,m;
int main()
{
    cin>>n>>m;//n,m如题
    for(int i=n;i<=m;i++)for(int tmp=i;tmp;tmp/=10)js[tmp%10]++;
    for(int i=0;i<=9;i++)cout<<js[i]<<" ";
    return 0;
}
