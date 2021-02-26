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
const int mm = 1000;
struct edge{
    int v,w;
}e[mm];

int n,m,h[mm],nex[mm],x,y,cnt=0,f[mm][mm]={0};

void add(int u,int v,int w){
    e[++cnt].v = v;
    e[cnt].w = w;
    nex[cnt] = h[u];
    h[u] = cnt;
}
int siz_x[mm]={0};
void dfs(int root,int fa){
    
    for(int i=h[root];i;i = nex[i]){
        int v = e[i].v;
        if(v==fa) continue;
        dfs(v,root);
        siz_x[root]+=siz_x[v]+1;
        for(int l = min(siz_x[root],n-1);l;l--){
            for(int k = min(siz_x[v],l-1);k>=0;k--){
                f[root][l]=max(f[root][l],f[root][l-k-1]+f[v][k]+e[i].w);
            }
        }
    }
}

int main(int argc, char *argv[])
{
    cin>>n>>m;
    int w;
    for(int i=1;i<n;i++){
        scanf("%d%d%d",&x,&y,&w);
        // cout<<"w="<<w<<' ';
        add(x,y,w);
        add(y,x,w);
    }
    dfs(1,-1);
    /* for(int i=1;i<n;i++){
     *     cout<<f[1][i]<<' ';
     * } */
    cout<<f[1][m]<<endl;
    return 0;
}
