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
int g[1006][1005]={0};
int n;
int main(int argc, char *argv[])
{
  cin>>n;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=i;j++){
      scanf("%d",&g[i][j]);
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=i;j++){
       g[i][j]+=max(g[i-1][j-1],g[i-1][j]);
       /* [>cout<<g[i][j]<<' ';<] */
    }
  }
    int ans=0;
  for(int i=0;i<=n;i++){
    ans=max(ans,g[n][i]);
  }
  cout<<ans<<endl;
  return 0;
}

