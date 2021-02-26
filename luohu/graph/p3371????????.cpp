#include "vector"
#include "bits/stdc++.h"
#include "map"
#include "queue"
#include "algorithm"
#include "stdio.h"
#include "iostream"
#include <cstring>
#include <queue>
#include <utility>
using namespace std;
struct edge{
  int to,val,next;
}e[500005];

int head[20009];
int cnt=0;

inline void add(int u,int v,int w){
  cnt++;
  e[cnt].to=v;
  e[cnt].val=w;
  e[cnt].next=head[u];
  head[u]=cnt;
}

int n,m,s;
int d[20000],vis[20000];


struct cmp//比较函数，利用点号的dist数值排序
{
	bool operator()(int x,int y)
	{
		return d[x]>d[y];//大于(>)为小根堆（头最小），反之亦然；
	}
};
int main(int argc, char *argv[])
{
  cin>>n>>m>>s;
  for(int i=1;i<=m;i++){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    add(a,b,c);
  }
  memset(d, 0x3f3f3f3f, sizeof(d));
  memset(vis, 0, sizeof(vis));
  d[s]=0;

  priority_queue<int,vector<int>,cmp > q;
  q.push(s);
  while(!q.empty()){
    int u=q.top();
    q.pop();
    if(vis[u]) continue;
    vis[u]=1;
    for(int t=head[u];t;t=e[t].next){
      int w=e[t].to;
      d[w]=min(d[w],d[u]+e[u].val);
      q.push(w);
      }
    
  }
  for(int i=1;i<=n;i++){
    // cout<<d[i]<<' ';
    printf("%d ",d[i]==0x3f3f3f3f?2147483647:d[i]);
  }
  return 0;
}

