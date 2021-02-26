/*
 * @Author: @Katwo 
 * @Date: 2020-11-23 00:11:59 
 * @Last Modified by: @Katwo
 * @Last Modified time: 2020-11-23 00:31:22
 */
#include <iostream> 
#include <algorithm> 
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int f[101][101],p[101]={0},n,a,b,k;
int main(int argc, char const *argv[])
{

    cin>>n;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++){
        if(i==j) f[i][j]=0;
        else f[i][j]=0x3f3f3f3f;}}
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&a,&b,&k);
        p[i]=a;
        // cout<<a<<b<<c<<endl;
        if(b>0) {f[i][b]=1;f[b][i]=1;}
        if(k>0) {f[i][k]=1;f[k][i]=1;}
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<f[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    int ans=0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        int su=0;
        // cout<<p[i]<<' ';
        for(int j=1;j<=n;j++){
            su+=p[j]*f[i][j];
            // cout<<f[i][j]<<' ';
        }
        // cout<<endl;
        ans=min(ans,su);
    }
    cout<<ans;
    return 0;
}
