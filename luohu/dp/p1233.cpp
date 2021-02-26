#include "vector"
#include "bits/stdc++.h"
#include "map"
#include "queue"
#include "algorithm"
#include "stdio.h"
#include "iostream"
#include <algorithm>
#include <cstring>
#define ll long long
#define ui unsigned int
#define INF 0x3f3f3f3f
#define low_bit(x) ((x)&(-x))
#define  mm  5006
using namespace std;

struct stick{
  int l,w;
}a[mm];

bool cmp(stick x,stick y){
  if(x.l==y.l) return x.w>y.w;
  return x.l>y.l;
}


int n,dp[mm];
int main(int argc, char *argv[])
{
  cin>>n;
  for(int i =1 ;i<=n;i++){
    scanf("%d%d",&a[i].l,&a[i].w);
  }
  sort(a+1,a+n+1,cmp);
  memset(dp,INF,sizeof(dp));
  int ans=0;
  for(int i=1;i<=n;i++){
    if(dp[ans]<a[i].w) dp[++ans]=a[i].w;
    else{
      int j=lower_bound(dp,dp+ans,a[i].w)-dp;
      dp[j]=a[i].w;
    } 
  }  
  /* for(int i=0;i<=n;i++) cout<<dp[i]<<' '; */
  /* for(int i=1;i<=n;i++) cout<<a[i].l<<' '<<a[i].w<<endl; */
  //for(int i=0;i<=n;i++){
  //  if(dp[i]!=dp[0]) ans++;
  //  while(dp[ans]!=0x3f3f3f3f) ans++;
  cout<<ans+1<<endl;
  return 0;
}
