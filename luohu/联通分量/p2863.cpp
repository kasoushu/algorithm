#include "vector"
#include "bits/stdc++.h"
#include "map"
#include "queue"
#include "algorithm"
#include "stdio.h"
#include "iostream"
#define ll long long
#define INF 0x3f3f3f3f
#define low_bit(x) ((x)&(-x))
using namespace std;

const int mm = 50005;
const int mn = 20005;

int dfn[mn],low[mn]={0},vis[mn]={0},h[mm],stk[mn];
int tot=0,n,m,ans=0,top=0,dnt=0;
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
        while(y=stk[top--]){
            scc[y]=root;
            vis[y]=0;
            sz[root]++;
            if(y==root) break;
        }
    }

}

int main(int argc, char *argv[])
{
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i]) tarjan(i);
    }
    for(int i=1;i<=n;i++){
        // cout<<sz[i]<<' ';
        if(sz[i]>1) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
