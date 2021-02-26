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
const int mm = 100005;
int n;
ll a[mm]={0},ans=INF;

ll cal(int mid){
  ll kk=0;
  for(int i=1;i<=n;i++){
    kk+=abs((a[i]-mid));
  }
  return kk;
}

int main(int argc, char *argv[])
{
  cin>>n;
  for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
  /* int l=0,r=40000; */
  sort(a+1,a+1+n);
  ll mid = a[(1+n)/2];
  cout<<cal(mid);
  return 0;
}
