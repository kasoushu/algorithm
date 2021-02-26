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
const int mm = 500;
struct node {
    int ver,w;
}e[mm];
int h[mm],nex[mm],f[mm][mm]={0},cnt=0,n,m;

void add(int u,int v,int w){
   e[++cnt].ver = v;
   e[cnt].w = w;
   nex[cnt] = h[u];
   h[u] = cnt;
}
void dfs(int root){
    for(int i=h[root];i;i = nex[i]){
        int v = e[i].ver;
        dfs(v);
        for(int l=m+1;l>=1;l--){
            for(int j = 0 ;j<l;j++){
                f[root][l] = max(f[root][l],f[root][l-j]+f[v][j]);
            }
        }
    } 
}
int main(int argc, char *argv[])
{
    cin>>n>>m;
    int x,y;
    for(int i=1;i<=n;i++){
        scanf("%d%d",&x,&y);
        add(x, i, y);
        f[i][1] = y;
    }
    dfs(0);
    cout<<f[0][m+1]<<endl;
    return 0;
}
