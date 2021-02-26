#include "vector"
#include "bits/stdc++.h"
#include "map"
#include "queue"
#include "algorithm"
#include "stdio.h"
#include "iostream"
#include <cstring>
#include <iterator>
using namespace std;
const int mm = 500;
int n;
int d[mm],f[mm],a[mm],c1[mm],c2[mm];

int main(int argc, char *argv[])
{
  cin>>n;
  for(int i=1;i<=n;i++){
    scanf("%d",&a[i]);
  }
  int len=1;
  d[1] = a[1];
  f[1] = a[n];
  c1[1]=c2[n]=1;
  for(int i=2;i<=n;i++){
    if(a[i]>d[len]){
      d[++len] = a[i];
    }else{
      *lower_bound(d+1,d+1+len,a[i]) = a[i];
    }
    c1[i]=len;
  }
  int len2 =1;
  for(int i=n-1;i>0;i--){
    if(a[i]>f[len2]) f[++len2]=a[i];
    else{
      *lower_bound(f+1,f+1+len2,a[i]) = a[i];
    }
    c2[i]=len2;
  }
  int ans=0;
  for(int i=1;i<=n;i++){
    ans=max(ans,c1[i]+c2[i]-1);
  }
  cout<<n-ans;
  return 0;
}
