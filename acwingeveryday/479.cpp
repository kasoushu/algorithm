#include "vector"
#include "bits/stdc++.h"
#include "map"
#include "queue"
#include "algorithm"
#include "stdio.h"
#include "iostream"
#include <cstdio>
#define ll long long
#define INF 0x3f3f3f3f
#define low_bit(x) ((x)&(-x))
#define PII pair<int,int> 
using namespace std;

const int mm = 50;

int a[mm];
int n,dp[mm][mm];
int root[mm][mm];

void pri_root(int x,int y){
    if(x>y) return ;
    printf("%d ",root[x][y]);
    pri_root(x,root[x][y]-1);
    pri_root(root[x][y]+1,y);
}

int main(int argc, char *argv[])
{
    cin>>n;
    for(int i=1;i<=n;i++) { scanf("%d",&a[i]); }
    for(int i=0;i<=n;i++){
        root[i][i] = i;
        for(int j =0;j<=n;j++){
            dp[i][j]=0;
            if(i==j) dp[i][j] = a[i];
            if(i>j) dp[i][j] = 1;
        }
    }
    // for(int i=0;i<=n;i++){
    //     for(int j =0;j<=n;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    for(int len = 2;len <= n;len++){
        for(int i=1;i+len-1<=n;i++){
            int j = i+len-1;
            for(int k = i;k<=j;k++){
                
                int v = dp[i][k-1]*dp[k+1][j]+a[k];
                if(v>dp[i][j]){
                    dp[i][j] = v;
                    root[i][j] = k;
                }
            }
        }
    }
    cout<<dp[1][n]<<endl;
    // cout<<root[1][n];
    pri_root(1, n);
    return 0;
}
