#include "vector"
#include "bits/stdc++.h"
#include "map"
#include "queue"
#include "algorithm"
#include "stdio.h"
#include "iostream"
#include <cstring>
#define ll long long
#define INF 0x3f3f3f3f
#define low_bit(x) ((x)&(-x))
using namespace std;

const int mm = 50005;
const int mn = 20005;

int dfn[mn],low[mn]={0},vis[mn]={0},h[mm],stk[mn],out[mn]={0},in[mn]={0},val[mn],vv[mn];
int tot=0,n,m,r,top=0,dnt=0,sccn=0,ans=0;
int scc[mn]={0},sz[mn]={0};
struct edg{
    int nex,u,v;
}e[mm];

void add(int u,int v){
    e[++tot].u = u;
    e[tot].v = v;
    e[tot].nex = h[u];
    h[u] = tot;
}

void tarjan(int root){
    vis[root]=1;stk[++top] = root;
    low[root]=dfn[root] = ++dnt;
    for(int i=h[root];i;i=e[i].nex){
        int go=e[i].v;
        if(!dfn[go]){
            tarjan(go);
            low[root]=min(low[root],low[go]);
        }else if(vis[go]){
            low[root]=min(low[root],low[go]);
        }
    }
    
    if(low[root]==dfn[root]){
        int y;
        sccn++;
        while(y=stk[top--]){
            scc[y]=sccn;
            vis[y]=0;
            sz[sccn]++;
            vv[sccn]=min(vv[sccn],val[y]);
            if(y==root) break;
        }
    }

}

int main(int argc, char *argv[])
{
    cin>>n;
    memset(val,INF,sizeof(val));
    memset(vv, INF, sizeof(vv));
    cin>>m;
    for(int i=1;i<=m;i++){
        int x,w;
        scanf("%d%d",&x,&w);
        val[x]=w;
    }
    cin>>r;
    for(int i=1;i<=r;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i]&&val[i]!=INF){
            tarjan(i);
        }
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i]){
            cout<<"NO"<<endl;
            cout<<i<<endl;
            return 0;
        }
    }
    for(int u=1;u<=n;u++){
        for(int i=h[u];i;i=e[i].nex){
            if(scc[u]!=scc[e[i].v]){
                in[scc[e[i].v]]++;
            }
        }
    }
    for(int i=1;i<=sccn;i++){
        if(in[i]==0) ans+=vv[i];
    }
    cout<<"YES"<<endl<<ans<<endl;
    return 0;
}

