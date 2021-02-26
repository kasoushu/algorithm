#include <iostream> 
#include <algorithm> 
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int n,m,k,a;
int c[1005][1005]={0};

int main(int argc, char const *argv[])
{
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a);c[i][j]=a+c[i-1][j]+c[i][j-1]-c[i-1][j-1];
        } 
    }
    int mm=-0x7fffffff,mx,my;
    for(int i=k;i<=n;i++){
        for(int j=k;j<=m;j++){
            int num=c[i][j]-c[i-k][j]-c[i][j-k]+c[i-k][j-k];
            if(num>mm){
                mm=num;
                mx=i-k+1;my=j-k+1;
            }
        } 
    }
    cout<<mx<<' '<<my;
    return 0;
}
