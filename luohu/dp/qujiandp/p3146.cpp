#include "vector"
#include "bits/stdc++.h"
#include "map"
#include "queue"
#include "algorithm"
#include "stdio.h"
#include "iostream"
#define ll long long
#define INF 0x3f3f3f3f
#define low_bit(x) ((x)&(-x))
using namespace std;

const int mm = 500;

int n,a[mm],dp[mm][mm];

int main(int argc, char *argv[])
{
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        dp[i][i]=a[i];
    }
    int ans=0;
    for(int l=2;l<=n;l++){
        for(int i=1;i+l-1<=n;i++){
            int j=i+l-1;
            for(int k=i;k<j;k++){
                if(dp[i][k]==dp[k+1][j]){
                    dp[i][j]=max(dp[i][j],dp[i][k]+1);
                    ans=max(ans,dp[i][j]);
                }
            }
        }
    }
    cout<<ans<<endl;

    return 0;
}
