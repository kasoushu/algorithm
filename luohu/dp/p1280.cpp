#include "vector"
#include "bits/stdc++.h"
#include "map"
#include "queue"
#include "algorithm"
#include "stdio.h"
#include "iostream"
#include <algorithm>
#include <cstring>
using namespace std;
const int mm = 10050;
struct node{
  int beg,end;
}a[mm];

int dp[mm],b[mm];
int n,m;



int main(int argc, char *argv[])
{
  cin>>n>>m;
  memset(b,0,sizeof(b));
  for(int i=1;i<=m;i++){
    scanf("%d%d",&a[i].beg,&a[i].end);
    b[a[i].beg]++;
  }
  sort(a+1,a+1+m,[](node x,node y){
      return x.beg>y.beg;
      });
  int num=1;
  for(int i=n;i>=1;i--){
    if(b[i]==0){
      dp[i]=dp[i+1]+1;
    }else{
      for(int j=1;j<=b[i];j++){
        dp[i]=max(dp[i],dp[i+a[num].end]);
        num++;
      }
    }
  } 
  /* for(int i=1;i<=n;i++) cout<<dp[i]<<' '; */
  cout<<dp[1];
  return 0;
}
