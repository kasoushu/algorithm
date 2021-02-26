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
using namespace std;

int main(int argc, char *argv[])
{
  int a[7]={4,5,2,2,3,3,4};
  int dp[10];

  memset(dp,0x1f,sizeof(dp));
  int mx=dp[0];
  for(int i=0;i<7;i++){
    *lower_bound(dp,dp+6,a[i])=a[i];
  }

  for(int i=0;i<10;i++) cout<<dp[i]<<' ';
  return 0;
}
