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

int n,m;
int a[500][500],g[500];
const int mod = 1000007;
int main(int argc, char *argv[])
{
  cin>>n>>m;
  for(int i=1;i<=n;i++){
    scanf("%d",&g[i]);
  }
  a[0][0]=1;
  for(int i=1;i<=n;i++){
    for(int j=0;j<=m;j++){
      for(int k=0;k<=min(j,g[i]);k++){
        a[i][j]=(a[i][j]+a[i-1][j-k])%mod;
      }
    }
  }
  
  cout<<a[n][m]<<endl;
  return 0;
}
