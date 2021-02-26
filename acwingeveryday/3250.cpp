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
#define PII pair<int,int> 
using namespace std;

const int mn=1005,mm=10050;

int e[mm][2],h[mm][2],nex[mm][2],tot[2];
bool vis[mm][2];
int n,m;
void add(int u,int v,int t){
    tot[t]++;
    e[tot[t]][t]=v;
    nex[tot[t]][t]=h[u][t];
    h[u][t]=tot[t];
}

bool ch(){
    for(int i=1;i<=n;i++){
        if(!vis[i][0]&&!vis[i][1]) return false;
    }
    return true;
}

void dfs(int u,int t){

    for(int k=h[u][t];k;k=nex[k][t]){
        int p=e[k][t];
        if(!vis[p][t]){
            vis[p][t]=1;
            dfs(p,t);
        }
    }
}

int main(int argc, char *argv[])
{
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y,0);
        add(y,x,1);
    }
    // for(int i=h[1][0];i;i=nex[i][0]){
    //     cout<<e[i][0]<<' ';
    // }

    int cnt=0;
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof(vis));
        vis[i][0]=vis[i][1]=1;
        dfs(i,0),dfs(i,1);
        if(ch()) cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
