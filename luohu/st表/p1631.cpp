#include "vector"
#include "bits/stdc++.h"
#include "map"
#include "queue"
#include "algorithm"
#include "stdio.h"
#include "iostream"
#include <cmath>
#include <functional>
using namespace std;

#define ll long long

const int maxn = 100009;

ll a[maxn],b[maxn];

priority_queue<ll,vector<ll>,greater<ll> > p;

int main(int argc, char *argv[])
{
 int n;
 cin>>n;
 for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
 for(int i=1;i<=n;i++) scanf("%lld",&b[i]);

 for(int i=1;i<=sqrt(n);i++){
   for(int j=i;j<=n/i;j++) p.push(a[j]+b[i]);
   for(int j=i+1;j<=n/i;j++) p.push(a[i]+b[j]);
 }
 for(int i=0;i<n;i++){
   printf("%lld",p.top());
   p.pop();
 }
  return 0;
}
