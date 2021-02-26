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

ll dp[mm][mm],a[mm];
int n;

int main(){
	
  cin>>n;
  
  for(int i=1;i<=n;i++){scanf("%lld",&a[i]);a[i+n]=a[i];}
  ll ans=0;
  for(int len=2;len<=n+1;len++){
    for(int i=1;i+len-1<=2*n;i++){
      int j=i+len-1;
      for(int k=i+1;k<j;k++){
        dp[i][j]=max(dp[i][j],dp[i][k]+dp[k][j]+a[i]*a[j]*a[k]);
        ans=max(ans,dp[i][j]);
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}

