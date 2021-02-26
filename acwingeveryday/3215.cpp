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

const int mm = 20050;

int n,m;
int e[mm],h[mm],nex[mm],tot=0;
int node,dis[mm],vis[mm];
void add(int u,int v){
    e[++tot]=v;
    nex[tot]=h[u];
    h[u]=tot;
}

int bfs(int u){
    queue<int> q;
    memset(vis,0,sizeof(vis));
    q.push(u);
    vis[u]=1;
    int res=0,dis=0;
    while(!q.empty()){
        int len = q.size();
        while(len--){
            int p=q.front();
            // cout<<p<<' ';
            q.pop();
            node=p; 
            res = max(dis,res);
            for(int i=h[p];i;i=nex[i]){ 
                int now=e[i]; 
                if(!vis[now]) {
                    // cout<<p<<" 's son  "<<now<<' ';
                    vis[now]=1;
                    q.push(now);
                }
            }
        }
        dis++;
    }
    return res;
}

int main(int argc, char *argv[])
{
    cin>>n>>m;
    int u;
    // cout<<n<<' '<<m<<endl;
    for(int i=2;i<=n;i++){
        cin>>u;
        add(u,i);
        add(i,u);
    }
    for(int i=1;i<=m;i++){
        cin>>u;
        add(u,i+10000);
        add(i+10000,u);
    }
    // cout<<"hello world";
    bfs(1);
    // cout<<node<<endl;
    int ans = bfs(node);
    cout<<ans<<endl;
    return 0;
}
