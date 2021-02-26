#include "vector"
#include "bits/stdc++.h"
#include "map"
#include "queue"
#include "algorithm"
#include "stdio.h"
#include "iostream"
using namespace std;
int v[10005]={0},w[10005]={0},dp[10005]={0};
int main(int argc, char *argv[])
{
  int n,m;
  cin>>n>>m;
  for(int i=1;i<=m;i++){
    scanf("%d%d",&w[i],&v[i]);
  }
  for(int i=1;i<=m;i++){
    for(int j=w[i];j<=n;j++){
      dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
    }
  }
  cout<<dp[n]<<endl;
  return 0;
}
