#include "vector"
#include "bits/stdc++.h"
#include "map"
#include "queue"
#include "algorithm"
#include "stdio.h"
#include "iostream"
#include <cstring>
#include <utility>
#define ll long long
#define INF 0x3f3f3f3f
#define low_bit(x) ((x)&(-x))
#define PII pair<int,int> 
using namespace std;
struct node{
    int x,y;
}dot[2];
const int mm = 205;
char g[mm][mm];
int vis[mm][mm];
int t,r,c;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int ans=INF;
bool flag = 0;

void dfs(int x,int y,int p){
    cout<<"dfs"<<endl;
    if(vis[x][y]) return;
    if(x==dot[1].x&&y==dot[1].y){
        flag=1;
        ans = min(ans,p);
        return ;
    }
    vis[x][y] = 1;
    for( int i =0 ;i<4; i++){
        int nx = x+dx[i],ny = y + dy[i];
        if(nx>=1&&nx<=r&&ny>=1&&ny<=c&&!vis[nx][ny]&&g[nx][ny]!='#'){
            dfs(nx,ny,p+1);
        }
    }
}


int main(int argc, char *argv[])
{
    cin>>t;
    while(t--){
        cin>>r>>c;
        // cout<<"rc   "<<r<<' '<<c<<endl;
        ans=INF,flag=0;
        for(int i =1 ;i<=r;i++){
            for(int j=1;j<=c;j++){
                // scanf("%c",&g[i][j]);
                cin>>g[i][j];
                if(g[i][j]=='S') dot[0].x=i,dot[0].y=j;
                if(g[i][j]=='E') dot[1].x=i,dot[1].y=j;
            }
        }
        memset(vis,0,sizeof(vis));
        dfs(dot[0].x,dot[0].y,0);
        if(flag){
            cout<<ans<<endl;
        }else{
            cout<<"oop!"<<endl;
        }
    }
    return 0;
}
