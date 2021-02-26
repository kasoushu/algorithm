#include "vector"
#include "bits/stdc++.h"
#include "map"
#include "queue"
#include "algorithm"
#include "stdio.h"
#include "iostream"
#include <cstring>
using namespace std;

const int mm = 2009;

int dp[mm][mm];
string a,b;

//dp[i][j]表示a的i->b的j 的最少次数
//当b为空时，需要修改的次数为len1
int main(int argc, char *argv[])
{
  cin>>a>>b;
  int l1=a.size();
  int l2=b.size();
  for(int i=0;i<=l1;i++) dp[i][0]=i;
  for(int i=0;i<=l2;i++) dp[0][i]=i;
  for(int i=1;i<=l1;i++){
    for(int j=1;j<=l2;j++){
      if(a[i-1]==b[j-1]){dp[i][j]=dp[i-1][j-1];continue;}
      else{
          dp[i][j]=min(min(dp[i-1][j-1],dp[i-1][j]),dp[i][j-1])+1; 
      }
    }
  }
  cout<<dp[l1][l2];
  return 0;
}
