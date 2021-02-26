#include "vector"
#include "bits/stdc++.h"
#include "map"
#include "queue"
#include "algorithm"
#include "stdio.h"
#include "iostream"
#include <algorithm>
#include <functional>
#define ll long long
#define ui unsigned int
#define INF 0x3f3f3f3f
#define low_bit(x) ((x)&(-x))
const int mm = 100009;
using namespace std;

int a[mm],da[mm],db[mm];
int n;

int main(int argc, char *argv[])
{
  n=0;
  while(cin>>a[++n]);
  //cout<<n<<endl; 
  n--;
  da[0]=db[0]=a[1];         // da 表示最长上升，db表示最长不上升
  int len1=0,len2=0; //
  for(int i=2;i<=n;i++){
    if(a[i]>da[len1]) da[++len1] = a[i];
    else{
      int p = lower_bound(da,da+len1,a[i]) - da ;
      da[p]=a[i];
    }

    if(a[i]<=db[len2]) db[++len2] = a[i];
    else{
      *upper_bound(db,db+len2,a[i],greater<int>() ) = a[i];
    }
  }
  //for(int i=0;i<=len1;i++) cout<<da[i]<<' ';
  //for(int i=0;i<=len2;i++)cout<<db[i]<<' ';
  cout<<len2+1<<endl<<len1+1;
  
  return 0;
}
