#include <iostream> 
#include <algorithm> 
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <bits/stdc++.h>
using namespace std;
int n;
long long  a[20005],dp[20005]={0},ans=-9999999;
int main(int argc, char const *argv[])
{
    cin>>n;
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
   // for(int i=1;i<=n;i++) {prefix[i]=prefix[i-1]+a[i];}
    for(int i=1;i<=n;i++){
        dp[i]=max(dp[i-1]+a[i],a[i]);
        cout<<dp[i]<<' '<<a[i]<<endl;
    }
    for(int i=1;i<=n;i++) {ans=max(ans,dp[i]);}
    cout<<ans<<endl;
    return 0;
}
