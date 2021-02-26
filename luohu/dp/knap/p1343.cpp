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

int a[500][500]={0},dp[500][500]={0};
int n,m;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int dfs(int i,int j){
  if(dp[i][j]) return dp[i][j];
  dp[i][j]=1;
  for(int k=0;k<4;k++){
    int xx=i+dx[k],yy=j+dy[k];
    if(xx>0&&yy>0&&xx<=n&&yy<=m&&a[xx][yy]>a[i][j]){
      dfs(xx,yy);
      dp[i][j]=max(dp[i][j],dp[xx][yy]+1);
    }
  }
  return dp[i][j];
}


int main(int argc, char *argv[])
{
  cin>>n>>m;
  for(int i=1;i<=n;i++){
    for(int j = 1;j<=m;j++){
      scanf("%d",&a[i][j]);
    }
  }
  int ans=0;
  for(int i=1;i<=n;i++){
    for(int j = 1;j<=m;j++){
        ans=max(ans,dfs(i,j));
    }}
  cout<<ans<<endl;
  return 0;
}
