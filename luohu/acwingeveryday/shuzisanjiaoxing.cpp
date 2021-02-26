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

int n;
int a[1000][1000];

int main(int argc, char *argv[])
{
  cin>>n;
  for(int i=0;i<1000;i++){
    for(int j=0;j<1000;j++){
      a[i][j]=-50000;
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=i;j++){
      scanf("%d",&a[i][j]);
    }
  }
  for(int i=2;i<=n;i++){
    for(int j=1;j<=i;j++){
      a[i][j]+=max(a[i-1][j],a[i-1][j-1]);
    }
  }
  int ans=0;
  for(int i=1;i<=n;i++){
    ans=max(a[n][i],ans);
  }
  cout<<ans;
  return 0;
}
