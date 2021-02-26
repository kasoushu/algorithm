#include "vector"
#include "bits/stdc++.h"
#include "map"
#include "queue"
#include "algorithm"
#include "stdio.h"
#include "iostream"
#include <regex>
#include <utility>
#include <vector>
#define ll long long
#define INF 0x3f3f3f3f
#define low_bit(x) ((x)&(-x))
using namespace std;

const int mm = 10005;

struct edg{
    int from,to,nex;
}e[mm*10];

int instk[mm]={0},scc[mm],nn=0,stk[mm],dfn[mm],low[mm],df=0,top=0,scc_z[mm]={0};
int h[mm*10],tot=0;
int n,m;

void add(int u,int v){
    e[++tot].from = u;
    e[tot].to = v;
    e[tot].nex=h[u];
    h[u]=tot;
}

void tarjan(int u){
    instk[u]=1;stk[++top]=u;
    low[u]=dfn[u]=++df;
    
    for(int i=h[u];i;i=e[i].nex){
        int v=e[i].to;
        if(!dfn[v]){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }else if(instk[v]){
            low[u]=min(low[u],low[v]);
        }
    }
    if(low[u]==dfn[u]){
        int y;
        nn++;
        // cout<<"scc "<<u<<endl;
        while(y=stk[top--]){
            scc[y]=nn;
            instk[y]=0;
            scc_z[nn]++;
            if(y==u) break;
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
    int out[mm]={0};
    for(int i=1;i<=n;i++){
        for(int k=h[i];k;k=e[k].nex){
            int v=e[k].to;
            if(scc[v]!=scc[i]){
                out[scc[i]]++;
            }
        }
    }
    // for(int i=1;i<=n;i++) cout<<out[scc[i]]<<' '<<scc[i]<<endl;
    int ans=0,anscnt=0;
    for(int i=1;i<=nn;i++){
        if(out[i]==0){
            ans=i;
            anscnt++;
        }
    }
    if(anscnt>1){cout<<0<<endl;return 0;}
    cout<<scc_z[ans]<<endl;
    return 0;
}
