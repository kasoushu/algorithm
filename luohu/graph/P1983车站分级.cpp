#include <iostream> 
#include <algorithm> 
#include <vector>
#include "bits/stdc++.h"
using  namespace std;

vector<vector<int> > g;
int n,m,ans=0;
int ru[1005]={0},s[1005][1005],d[1005][1005]={0};
bool vis[1005];


void bfs(){
    queue<pair<int,int> > q;
    for(int i=1;i<=n;i++){if(ru[i]==0) q.push(make_pair(i,1));}
    ans=1;
    while(!q.empty()){
        
        int k=q.front().first;
        int val=q.front().second;
        // cout<<"while "<<k<<endl;
        q.pop();
        for(int i=0;i<g[k].size();i++){
            int w=g[k][i];
            ru[w]--;
            if(ru[w]==0){
            // cout<<"jinrufor "<<w<<endl;
            q.push(make_pair(w,val+1));
            ans=max(ans,val+1);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    cin>>n>>m;
    g.resize(n+2);
    for(int i=1;i<=m;i++){
        scanf("%d",&s[i][0]);
        memset(vis,0,sizeof(vis));
        for(int j=1;j<=s[i][0];j++){
            scanf("%d",&s[i][j]);
            vis[s[i][j]]=1;
        }
        // cout<<"line end"<<endl;
        for(int j=s[i][1];j<=s[i][s[i][0]];j++){
            if(vis[j]) continue;
            for(int k=1;k<=s[i][0];k++){
                if(!d[j][s[i][k]]){
                    d[j][s[i][k]]=1;
                    ru[s[i][k]]++;
                    g[j].push_back(s[i][k]);
                }
            }
        }
    }

    bfs();
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++) cout<<d[i][j];
    //     cout<<endl;
    // }
    // for(int i=1;i<=n;i++) cout<<ru[i];
    cout<<ans;
    return 0;
}