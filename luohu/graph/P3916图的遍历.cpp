#include <iostream> 
#include <algorithm> 
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <bits/stdc++.h>
using namespace std;
int n,m;
vector< vector<int> > g;
int ans[100005]={0};
void dfs(int root,int x){
    if(ans[root]>0) return;
    // cout<<root<<' '<<x<<endl;
    ans[root]=x;
    for(int &k:g[root]){
        dfs(k,x);
    }
}
int main(int argc, char const *argv[])
{
    /* code */
    cin>>n>>m;
    g.resize(n+2);
    int u,v;
    for(int i=0;i<m;i++){
        scanf("%d%d",&u,&v);
        g[v].push_back(u);
    }
    for(int i=n;i>=1;i--){
        dfs(i,i);
    }
    for(int i=1;i<=n;i++){
        printf("%d ",ans[i]);
    }
    return 0;
}
