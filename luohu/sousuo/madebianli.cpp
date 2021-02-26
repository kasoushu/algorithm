#include "iostream"
#include "vector"
#include "queue"
using namespace std;

int n,m,mx,my;
int grid[1000][1000];
int dx[9]={0,2,1,-1,-2,-2,-1,1,2};
int dy[9]={0,1,2,2,1,-1,-2,-2,-1};

void bfs(){
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) grid[i][j]=-1;
    queue< pair<int ,int > > q;
    q.push(make_pair(mx,my));
    grid[mx][my]=0;
    while (!q.empty()){
        pair<int ,int > now_point=q.front();q.pop();
        int already_path=grid[now_point.first][now_point.second];
        for(int i=1;i<=8;i++){
            int  next_x=now_point.first+dx[i],next_y=now_point.second+dy[i];
            if(next_x>=1&&next_x<=n&&next_y>=1&&next_y<=m&&grid[next_x][next_y]==-1){
                q.push(make_pair(next_x,next_y));
                grid[next_x][next_y]=already_path+1;
            }
        }
    }
    

}

int main(int argc, char const *argv[])
{
    cin>>n>>m>>mx>>my;
    bfs();
    for(int i=1;i<=n;i++) {for(int j=1;j<=m;j++) printf("%-5d",grid[i][j]); cout<<endl;}

    return 0;
}
