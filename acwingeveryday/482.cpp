#include "vector"
#include "bits/stdc++.h"
#include "map"
#include "queue"
#include "algorithm"
#include "stdio.h"
#include "iostream"
#include <algorithm>
#define ll long long
#define INF 0x3f3f3f3f
#define low_bit(x) ((x)&(-x))
using namespace std;

const int mm = 100050;
int n,dp[mm],a[mm],dr[mm];


int main(int argc, char *argv[])
{
    cin>>n;
    int len1=0,len2=0,ans=0;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    // memset(dp,INF,sizeof(dp));
    // memset(dr,INF,sizeof(dr));
    for(int i=1;i<=n;i++){
        if(a[i]>dp[len1]){
            dp[++len1] = a[i];
        }else{
            *lower_bound(dp+1,dp+len1,a[i]) = a[i];
        }
        if(a[n-i+1]>dr[len2]){
            dr[++len2] = a[n-i+1];
        }else{
            *lower_bound(dr+1,dr+1+len2,a[n-i+1]) = a[n-i+1];
        }
        cout<<len1<<" = len = "<<len2<<endl;
        ans=max(ans,len1+len2);
    }
    // for(int i=1;i<=n;i++){
    //     cout<<dp[i]<<"   "<<dr[i]<<endl;
    // }
    cout<<n-ans<<endl;
    return 0;
}
