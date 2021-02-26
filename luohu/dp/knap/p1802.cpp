#include "vector"
#include "bits/stdc++.h"
#include "map"
#include "queue"
#include "algorithm"
#include "stdio.h"
#include "iostream"
#define ll long long
#define ui unsigned int
#define INF 0x3f3f3f3f
#define low_bit(x) ((x)&(-x))
using namespace std;

ll fail[1005],w[1005],v[1005],dp[10010];
int n,m;


int main(int argc, char *argv[])
{
 scanf("%d%d",&n,&m); 
 for(int i=1;i<=n;i++){
   scanf("%lld%lld%lld",&fail[i],&v[i],&w[i]);
 }
  for(int i=1;i<=n;i++){
    for(int j=m;j>=w[i];j--){
      dp[j]=max(dp[j]+fail[i],dp[j-w[i]]+v[i]);
    }
    for(int j=w[i]-1;j>=0;j--){
      dp[j]+=fail[i];
    }

  }
  cout<<dp[m]*5;

  return 0;
}
