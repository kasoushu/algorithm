#include "vector"
#include "bits/stdc++.h"
#include "map"
#include "queue"
#include "algorithm"
#include "stdio.h"
#include "iostream"
#include <queue>
using namespace std;

int n,m;
struct func{
  int a,b,c;
}f[10005];

struct node{
  int n,x,val;
};

bool operator < (node a,node b){
  return a.val>b.val;
}

int main(int argc, char *argv[])
{
  cin>>n>>m;
  priority_queue<node,vector<node>> q;
  for(int i=1;i<=n;i++){
    scanf("%d%d%d",&f[i].a,&f[i].b,&f[i].c);
    q.push((node){i,1,f[i].a+f[i].b+f[i].c}); 
  }
  for(int i=1;i<=m;i++){
    node t=q.top();
    q.pop();
    printf("%d ",t.val);
    q.push((node){t.n,t.x+1,f[t.n].a*(t.x+1)*(t.x+1)+f[t.n].b*(t.x+1)+f[t.n].c});
  }
  return 0;
}
