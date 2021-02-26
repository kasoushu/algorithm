#include "vector"
#include "bits/stdc++.h"
#include "map"
#include "queue"
#include "algorithm"
#include "stdio.h"
#include "iostream"
#include <queue>
#define  MM 100005
using namespace std;

int n,m,dis[MM],head[MM],cnt=0;

struct edge{
  int to,w,nxt;
}e[MM];

struct node{
  int dis,v;
  bool  operator < (const node &k) const {
    return dis>k.dis;
  }
};


void add(int u,int v,int w){
  cnt++;
  e[cnt].to=v;
  e[cnt].nxt=head[u];
  e[cnt].w=w;
  head[u]=cnt;
}
void dijkstra(int s){
  for(int i=0;i<=n*2;i++) dis[i]=0x3f3f3f3f;
  dis[s]=0; 
  priority_queue<node> q;
  q.push((node){0,s});
  while(!q.empty()){
    node fr=q.top();
    q.pop();
    int u=fr.v,d=fr.dis;
    if(dis[u]!=d) continue;
    for(int k=head[u];k;k=e[k].nxt){
      int w=e[k].to;
      if(dis[w]>dis[u]+e[k].w){
        dis[w]=dis[u]+e[k].w;
        q.push((node){dis[w],w});
      }
    }
  }
}
int main(int argc, char *argv[])
{
  cin>>n>>m;
  for(int i=1;i<=m;i++){
    int x,y,z;
    scanf("%d%d%d",&x,&y,&z);
    add(x,y,z);
    add(y+n,x+n,z);
  }
  int ans=0;
  dijkstra(1);
  for(int i=1;i<=n;i++) ans+=dis[i];
  dijkstra(1+n);
  for(int i=n+2;i<=2*n;i++)ans+=dis[i];
  cout<<ans;
  return 0;
}
