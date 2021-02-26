#include "vector"
#include "bits/stdc++.h"
#include "map"
#include "queue"
#include "algorithm"
#include "stdio.h"
#include "iostream"
#include <functional>
#include <queue>
#include <utility>
#include <vector>
#define ll long long
#define ui unsigned int
#define INF 0x3f3f3f3f
#define low_bit(x) ((x)&(-x))

typedef std::pair<int,int> pii;
using namespace std;


const int mm = 400005;
const int mn = 5005;
struct edge{
  int v,w;
}e[mm];

struct edg{
  int u,v,w;
}ek[mm];

int h[mm],nex[mm],cnt=0;
int a[mn]={0};
int n,m;
void add(int u,int v,int w){
  e[++cnt].v = v;
  e[cnt].w = w;
  nex[cnt]   = h[u];
  h[u]     = cnt;
}
int find(int x){ return a[x]==x?x:a[x]=find(a[x]);}
void kruskul(){
  for(int i=1;i<=m;i++){
    int x,y,w;
    scanf("%d%d%d",&x,&y,&w);
    ek[++cnt].w=w;
    ek[cnt].u = x;
    ek[cnt].v = y;
  }
  sort(ek+1,ek+1+cnt,[](edg x,edg y){
      return x.w<y.w;
      });
  // for(int i=1;i<=cnt;i++){
  //   cout<<ek[i].u<<" "<<ek[i].v<<" "<<ek[i].w<<endl;
  // }
  for(int i=0;i<=n;i++){a[i]=i;}  //uni-set init
  int ans=0,cct=0;
  for(int i=1;i<=cnt;i++){
    int x=find(ek[i].u),y=find(ek[i].v);
    if(x==y) continue;
    else{
      a[x]=y;
      ans+=ek[i].w;
      cct++;
    }
    if(cct==n-1) break;
  }
  if(cct<n-1){cout<<"orz";}
  else cout<<ans<<endl;
}

void prim(){
  for(int i=1;i<=m;i++){
    int x,y,w;
    scanf("%d%d%d",&x,&y,&w);
    add(x,y,w);
    add(y,x,w);
  }
  int dis[mn],ans=0,vis[mn]={0};
  for(int i=0;i<=n;i++) dis[i]=INF;
  dis[1]=0;
    priority_queue<pii,vector<pii>,greater<pii> > qq;
    qq.push(make_pair(0,1));
    int cct=0;
    while(!qq.empty()&&cct<n){
        int td = qq.top().first;int tv = qq.top().second;
        qq.pop();
        if(vis[tv]) continue;
        vis[tv] = 1;
        ans+=td;
        cct++;
        for(int i=h[tv];i;i=nex[i]){
            int to = e[i].v;
            if(vis[to]) continue;
            dis[to] = min(dis[to],e[i].w);
            qq.push(make_pair(dis[to], to));
            // cout<<"push"<<dis[to]<<' '<<to<<endl;
        }
    
    if(cct<n) cout<<"orz";
    else cout<<ans<<endl;
}
int main(int argc, char *argv[])
{
  cin>>n>>m;
  //kruskul
  /* kruskul(); */
    prim();
  return 0;
}
