#include "vector"
#include "bits/stdc++.h"
#include "map"
#include "queue"
#include "algorithm"
#include "stdio.h"
#include "iostream"
#include <cstring>

using namespace std;
const int mm = 100005;
int d[mm],a[mm],b[mm],ma[mm];
int n;
int main(int argc, char *argv[])
{
  cin>>n;
  for(int i=1;i<=n;i++){
    scanf("%d",&a[i]);
    ma[a[i]]=i;
  }
  for(int i=1;i<=n;i++){
    scanf("%d",&b[i]);
    d[i]=0x3f3f3f3f;
  }
  int len=0;
  d[0]=0;
  for(int i=1;i<=n;i++){
    if(ma[b[i]]>d[len]) d[++len] = ma[b[i]];
    else{
      *lower_bound(d+1,d+1+len,ma[b[i]]) = ma[b[i]];
    }
  }
  /* cout<<endl;
   * for(int i=1;i<=len;i++){
   *   cout<<d[i]<<' ';
   * } */
  cout<<len;
  return 0;
}

