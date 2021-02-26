#include "vector"
#include "bits/stdc++.h"
#include "map"
#include "queue"
#include "algorithm"
#include "stdio.h"
#include "iostream"
#include <cmath>
#define ll long long
#define INF 0x3f3f3f3f
#define low_bit(x) ((x)&(-x))
using namespace std;

const int mm = 20000;

int to[mm],h[mm],nex[mm],cnt=0,n=0,dp[mm]={0},a[mm],vis[mm]={0};
int ans=0;
void add_edge(int u,int v){
    to[++cnt] = v;
    nex[cnt] = h[u];
    h[u] = cnt;
}
void dfs(int root,int fa){
    /* vis[root] = 1;  */
    dp[root] = a[root];
    for(int i=h[root];i;i=nex[i]){
        if(to[i]==fa) continue;
        dfs(to[i],root);
        dp[root] += max(0,dp[to[i]]);
    }
    ans=max(ans,dp[root]);
}


int main(int argc, char *argv[])
{
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        dp[i]=a[i];
    }
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        add_edge(x, y);
        add_edge(y, x);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++) cout<<dp[i]<<' ';
    cout<<ans<<endl;

    return 0;
}
