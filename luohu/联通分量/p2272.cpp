#include <iostream> 
#include <algorithm> 
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <bits/stdc++.h>
using namespace std;

const int mm = 10000005;
const int mn = 1000005;
struct edg
{
  int from,to,nex;
}e[mm],en[mm];

struct ed{
    int x,y;
}ex[mn];

int dist[mn],low[mn],dfn[mn],in[mn]={0},stk[mn],scc[mn]={0},siz[mn]={0},ans[mn]={0},out[mn]={0};
int n,m,tot=0,h[mm],he[mm],cnt=0,top=0,mod,sccnum=0,ans1=0,ans2=0,s=0,encnt=0;
bool vis[mn]={0};

void add_e(int u,int v){
    e[++tot].from = u;
    e[tot].to = v;
    e[tot].nex=h[u];
    h[u]=tot;
}

void add_n(int u,int v){
    en[++encnt].from = u;
    en[encnt].to=v;
    en[encnt].nex=he[u];
    he[u]=encnt;
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
        sccnum++;
        while(y=stk[top--]){
            scc[y]=u;
            vis[y]=0;
            siz[u]++;
            if(u==y) break;
        }
    }

}
void  tuopu(){
    queue<int> q;
    encnt=0;
    for(int i=1;i<=s;i++){
        if(ex[i].x!=ex[i-1].x||ex[i].y!=ex[i-1].y){
            add_n(ex[i].x,ex[i].y);
            in[ex[i].y]++;
            out[ex[i].x]++;
        }
    }

    for(int i=1;i<=n;i++){
        if(in[i]==0&&scc[i]==i){
            q.push(i);
            dist[i]=siz[i];
            ans[i]=1;
        }
    }
    while(!q.empty()){
        int k = q.front();q.pop();
        for(int i=he[k];i;i=en[i].nex){
            int v= en[i].to;
            if(dist[v]<dist[k]+siz[v]){
                dist[v]=dist[k]+siz[v];
                ans[v]=ans[k];
            }else if(dist[v]==dist[k]+siz[v]){
                ans[v] = (ans[v]%mod+ans[k]%mod)%mod;
            }
            in[v]--;
            if(in[v]==0) q.push(v);
        }
    }
    for(int i=1;i<=n;i++){
        if(scc[i]==i&&out[i]==0){
            if(dist[i]==ans1){
                ans2=(ans2%mod+ans[i]%mod)%mod;
            }
            if(dist[i]>ans1){
                ans1=dist[i],ans2=ans[i];
            }
        }
    }
}
int main(int argc, char *argv[])
{  
  cin>>n>>m>>mod;
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
  for(int i=1;i<=m;i++){
    int x=scc[e[i].from],y=scc[e[i].to];
    if(x!=y){
        ex[++s].x=x;
        ex[s].y=y;
    } 
  }
  sort(ex+1,ex+1+s,[](ed u,ed v){
        return u.x==v.x?(u.y<v.y):(u.x<v.x);
          });
//   cout<<"scc";
// for(int i=1;i<=n;i++) {
//         cout<<scc[i]<<' ';
//     }
// cout<<endl;
// for(int i=1;i<=n;i++) cout<<low[i]<<' ';
  tuopu();
  printf("%d\n%d",ans1,ans2);
  return 0;
}
