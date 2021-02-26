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

int dfn[mn],low[mn]={0},vis[mn]={0},h[mm],stk[mn],out[mn]={0},in[mn]={0};
int tot=0,n,m,r,ans2=0,top=0,dnt=0,sccn=0;
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
            if(y==root) break;
        }
    }

}

int main(int argc, char *argv[])
{
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int x;
            scanf("%d",&x);
            if(x==1) add(i,j);
        }
    }
    int ans1=0;
    for(int i=1;i<=n;i++){
        if(!dfn[i]){
            tarjan(i);
        }
    }
    ans1=0,ans2=0;
    for(int i=1;i<=n;i++){
        for(int j=h[i];j;j=e[j].nex){
            if(scc[i]!=scc[e[j].v]){
                out[scc[i]]++;
                in[scc[e[j].v]]++;
            }
        }
    }
    for(int i=1;i<=sccn;i++){
        if(in[i]==0) ans1++;
        if(out[i]==0) ans2++;
    }
    if(sccn==1) cout<<1<<endl;
    else {
        cout<<ans1<<endl;
        }
    return 0;
}

