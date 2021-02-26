#include <iostream> 
#include <algorithm> 
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <bits/stdc++.h>
using namespace std;
int ans=0;
int n,m;
int ii,jj;
char g[30][30];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
void bfs(int x,int y,bool vis[30][30]){
    // if((g[x][y]=='.'||g[x][y]=='@')&&vis[x][y]==0){
    //     // cout<<cnt<<' ';
    //     ans=max(ans,cnt);
    //     for(int i=0;i<4;i++){
    //         int nex=x+dx[i],ney=y+dy[i];
    //         vis[x][y]=1;
    //         dfs(nex,ney,cnt+1);
    //         vis[x][y]=0;
    //     }
    // }
    queue<pair<int,int> > q;
    int cnt=0;
    q.push(make_pair(x,y));
    while(!q.empty()){
        int nx=q.front().first,ny=q.front().second;
        q.pop();
        if(vis[nx][ny]==1) continue;
        vis[nx][ny]=1;
        cnt++;
        // cout<<cnt<<' ';
        for(int i=0;i<4;i++){
            int nex=nx+dx[i],ney=ny+dy[i];
            if(g[nex][ney]=='.'&&vis[nex][ney]==0&&nex>=1&&nx<=n&&ny>=1&&ny<=m){
                q.push(make_pair(nex,ney));
            }
        }
    }
    ans=cnt;
}


int main(int argc, char const *argv[])
{
    while(1){
        cin>>m>>n;
        if(m==0&&n==0) break;
        //cout<<n<<m;
        for(int i=1;i<=n;i++){
            string s;
            cin>>s;
            for(int j=0;j<m;j++) {g[i][j+1]=s[j];if(s[j]=='@') ii=i,jj=j+1;}
        }
        // cout<<ii<<' '<<jj<<endl;
        // cout<<123;
        bool vis[30][30]={0};
        bfs(ii,jj,vis);
        // cout<<123;
        cout<<ans<<endl;
    }
    return 0;
}
