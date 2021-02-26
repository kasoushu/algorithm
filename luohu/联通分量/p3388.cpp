#include <iostream> 
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <bits/stdc++.h>
using namespace std;
const int mm = 100005;
int n,m;
vector< vector<int> > e(100005);
int dfn[mm],low[mm],index=0,res=0;
bool vis[mm]={0},dot[mm]={0};

void tarjan(int u,int f){
    vis[u]=1;
    //cout<<u<<' '<<f<<endl;
    low[u]=dfn[u]= ++index;
    int child = 0;
    for(auto k:e[u]){
        if(!vis[k]){
            child++;
            tarjan(k,u);
            low[u] = min(low[u],low[k]);
            //if(k==6){cout<<"6 "<<low[k]<<' '<<dfn[u]<<endl;}
            if(f!=u&&low[k]>=dfn[u]&&!dot[u]){
                //cout<<"dot "<<u<<endl;
                dot[u]=1;
                res++;
            }
        }else if(k!=f){
            low[u] = min(low[u],dfn[k]);
        }
    }
    if(f==u&&child>=2&&!dot[u]){
        //cout<<">=2 "<<u<<' '<<f<<endl;
    dot[u]=1;
    res++;
}
}


int main(int argc, char const *argv[])
{
cin>>n>>m;
for(int i=1;i<=m;i++){
    int x,y;
    scanf("%d%d",&x,&y);
    e[x].push_back(y);
    e[y].push_back(x);

}
for(int i=1;i<=n;i++){
    if(!vis[i]){
        index=0;
        tarjan(i,i);
    }
}
cout<<res<<endl;
for(int i=1;i<=n;i++){
    if(dot[i]==1)
    printf("%d ",i);
    }
    // for(int i=1;i<=n;i++){
    //     cout<<dfn[i]<<' ';
    // }
    // for(int i=1;i<=n;i++){
    //     cout<<low[i]<<' ';
    // }
    //     for(int i=1;i<=n;i++){
    //     cout<<dot[i]<<' ';
    //}
    return 0;
}
