#include "iostream"
#include "queue"
using namespace std;

int grid[305][305],visit[305][305]={0};
int ans[305][305]={0};
int dx[5]={0,1,0,-1,0};
int dy[5]={0,0,1,0,-1};
int bfs(int b,int e){
    queue<pair<int ,int >> q;
    q.push(make_pair(b,e));
    visit[b][e]=1;
    while (!q.empty())
    {
        int last_x=q.front().first,last_y=q.front().second;
        int s=ans[last_x][last_y]+1;
        q.pop();
        if(grid[last_x][last_y]==-1||grid[last_x][last_y]==9999) { return s-1;}
        for(int i=1;i<5;i++){
            int next_x=last_x+dx[i],next_y=last_y+dy[i];
            if(visit[next_x][next_y]==0&&next_x>=0&&next_y>=0&&(grid[next_x][next_y]==-1||s<grid[next_x][next_y])){
                visit[next_x][next_y]=1;
                q.push(make_pair(next_x,next_y));
                ans[next_x][next_y]=s;
            }
        }
    }
    return -1;

}


int    main(int argc, char const *argv[])
{
    int n;
    int x,y,t;
    cin>>n;
    for (int i = 0; i < 305; i++)
    {
        for(int j=0;j<305;j++) grid[i][j]=9999;
    }
    for(int j=0;j<n;j++){
        cin>>x>>y>>t;
        for(int i=0;i<5;i++){
            if(x+dx[i]>=0&&x+dx[i]<305&&y+dy[i]>=0&&y+dy[i]<305) grid[x+dx[i]][y+dy[i]]=min(grid[x+dx[i]][y+dy[i]],t);
        }
    }

    cout<<bfs(0,0);
    return 0;
}
