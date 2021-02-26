#include <iostream> 
#include <algorithm> 
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <bits/stdc++.h>
using namespace std;
int n,a[150][150]={0},c[150][150]={0};

int main(int argc, char const *argv[])
{
    /* code */
    cin>>n;
    int ans=-999999;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) c[i][j]=c[i][j-1]+c[i-1][j]-c[i-1][j-1]+a[i][j];
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++){
            for(int x=1;x<=i;x++) 
                for(int y=1;y<=j;y++) ans=max(ans,c[i][j]+c[x-1][y-1]-c[i][y-1]-c[x-1][j]);
        }
        }
    cout<<ans;
    return 0;
}
