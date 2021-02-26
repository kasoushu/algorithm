#include <iostream> 
#include <algorithm> 
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int vis[1005],g[1005][1005]={0},cnt[1005]={0},ans,k,n,m;
int c[1005]={0};
void dfs(int root){
    vis[root]=1;
    cnt[root]++;
    for(int i=1;i<=n;i++){
        if(vis[i]==0&&g[root][i]>0){
            dfs(i);
        }
    }    
}


int main(int argc, char const *argv[])
{
    cin>>k>>n>>m;
    for(int i=1;i<=k;i++){
        cin>>c[i];
    }
    int ea,eb;
    for(int i=0;i<m;i++){
        scanf("%d%d",&ea,&eb);
        g[ea][eb]=1;
    }
    for(int i=1;i<=k;i++){
        memset(vis,0,sizeof(vis));
        dfs(c[i]);
    }
    for(int i=1;i<=n;i++){
        // cout<<cnt[i]<<' ';
       if(cnt[i]==k) ans++;
    }
    cout<<ans;
    return 0;
}
