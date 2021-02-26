#include "vector"
#include "bits/stdc++.h"
#include "map"
#include "queue"
#include "algorithm"
#include "stdio.h"
#include "iostream"
#include <cstring>
#define ll long long
#define INF 0x3f3f3f3f
#define low_bit(x) ((x)&(-x))
#define PII pair<int,int> 
using namespace std;

const int mm = 1005;
int n;
int dp[mm][mm];
int sum[mm],a[mm];
int main(int argc, char *argv[])
{
    cin>>n;
    memset(dp,INF,sizeof(dp));
    memset(sum,0,sizeof(sum));
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        sum[i]=sum[i-1]+a[i];
        dp[i][i]=0;
    }
    for(int len=2;len<=n;len++){
        for(int i=1;i<=n;i++){
            int j=i+len-1;
            for(int k=i;k<=j;k++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1]);
            }
        }
    }

    cout<<dp[1][n];

    return 0;
}
