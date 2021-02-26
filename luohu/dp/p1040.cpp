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
const int mm = 200; 
int n;
ll g[mm][mm],root[mm][mm];

void pri(int l,int r){
  if(l>r) return ;
  printf("%lld ",root[l][r]);
  if(l==r) return ;
  pri(l,root[l][r]-1);
  pri(root[l][r]+1,r);
}


int main(int argc, char *argv[])
{
  cin>>n;
  for(int i=1;i<=n;i++){
    scanf("%lld",&g[i][i]);
    root[i][i]=i;
    g[i][i-1]=1;
  }
  
  for(int len=1;len<n;len++){
    for(int i=1;i+len<=n;i++){
      int j=i+len;
      g[i][j]=g[i+1][j]+g[i][i];
      root[i][j]=i;
      for(int k=i+1;k<j;k++){
        if(g[i][k-1]*g[k+1][j]+g[k][k]>g[i][j]){
          g[i][j]=(g[i][k-1]*g[k+1][j]+g[k][k]);
          root[i][j]=k;
        }
      }
    }
  }
  cout<<g[1][n]<<endl;
  pri(1,n);
  return 0;
}
