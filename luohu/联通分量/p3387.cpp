#include <iostream> 
#include <algorithm> 
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <bits/stdc++.h>
using namespace std;

const int mm = 100005;
const int mn = 10005;
struct edg
{
  int from,to,nex;
}e[mm],en[mm];

int dist[mn],low[mn],dfn[mn],in[mn]={0},stk[mn],scc[mn]={0},p[mn];
int n,m,tot=0,h[mm],he[mm],cnt=0,top=0;
bool vis[mn]={0};

void add_e(int u,int v){
    e[++tot].from = u;
    e[tot].to = v;
    e[tot].nex=h[u];
    h[u]=tot;
}

void tarjan(int u){
    vis[u]=1;
    low[u]=dfn[u]=++cnt;
    stk[++top] = u;
    for(int i=h[u];i;i=e[i].nex){
        int v= e[i].to;
        if(!dfn[v]){
            tarjan(v);
            low[u]=min(low[u],low[v]);
            // cout<<"456  "<<low[u]<<' '<<low[v]<<endl;
        }else if(vis[v]){
            low[u]=min(low[u],low[v]);
            // cout<<"123  "<<low[u]<<' '<<low[v]<<endl;
        }
    }
    if(dfn[u]==low[u]){
        int y;
        while(y=stk[top--]){
            scc[y]=u;
            // cout<<"scc"<<u<<"<-"<<y<<endl;
            vis[y]=0;
            if(u==y) break;
            p[u]+=p[y];
        }
    }

}
int tuopu(){
    queue<int> q;
    
    for(int i=1;i<=n;i++){
        if(in[i]==0&&scc[i]==i){
            q.push(i);
            dist[i]=p[i];
        }
    }
    int ans=0; 
    while(!q.empty()){
        int k = q.front();q.pop();
        for(int i=h[k];i;i=en[i].nex){
            int v= en[i].to;
            dist[v] = max(dist[v],dist[k]+p[v]);
            in[v]--;
            if(in[v]==0) q.push(v);
        }
    }
    for(int i=1;i<=n;i++){
        ans=max(ans,dist[i]);
        // cout<<dist[i]<<' ';
    }
    return ans;
}
int main(int argc, char *argv[])
{  
  cin>>n>>m;
  for(int i=1;i<=n;i++){
    scanf("%d",&p[i]);
  }
  for(int i=1;i<=m;i++){
    int x,y;
    scanf("%d%d",&x,&y);
    add_e(x,y);
  }
  // cout<<"edge";
  // for(int i=1;i<=tot;i++) cout<<e[i].from<<' '<<e[i].to<<endl;
  // cout<<endl;
  for(int i=1;i<=n;i++){
    if(!dfn[i]) tarjan(i);
  }
  int s=0;
  for(int i=1;i<=m;i++){
    int x=scc[e[i].from],y=scc[e[i].to];
    if(x!=y){
        en[++s].from = x;
        en[s].to = y;
        en[s].nex = he[x];
        he[x]=s;
        in[y]++;
    } 
  }
//   cout<<"scc";
// for(int i=1;i<=n;i++) {
//         cout<<scc[i]<<' ';
//     }
// cout<<endl;
// for(int i=1;i<=n;i++) cout<<low[i]<<' ';
  printf("%d",tuopu());
  return 0;
}
