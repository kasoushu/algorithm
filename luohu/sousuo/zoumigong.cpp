#include "iostream"
#include "algorithm"
using namespace std;

typedef struct 
{
    int x;
    int y;
}node;
int map[1000][1000]={0};
int ans=0;
int n,m,oc;
int x1,y1,x2,y2;

int fangxiang[5][2]={{0,0},{0,1},{0,-1},{1,0},{-1,0}};
int visited[100][100]={0};
void search(int w,int v){
    // if(w<1||w>n||v<1||v>m) return;
    if(w==x2&&v==y2) {ans++;return;}
    for(int i=1;i<=4;i++){
        int nx=w+fangxiang[i][0],ny=v+fangxiang[i][1];
        if (nx<=n&&nx>=1&&ny>=1&&ny<=m&&map[nx][ny]==0&&visited[nx][ny]==0)
        {
            visited[nx][ny]=1;
            search(nx,ny);
            visited[nx][ny]=0;
        }  
    }
}

int main(int argc, char const *argv[])
{
    cin>>n>>m>>oc;
    cin>>x1>>y1>>x2>>y2;
    visited[x1][y1]=1;
    for(int i=1;i<=oc;i++) {int o,b;cin>>o>>b;map[o][b]=1;}
    search(x1,y1);
    std::cout<<ans;
    return 0;
}

// #include "iostream"
// #include "algorithm"

// using namespace std;

// typedef struct 
// {
//     int x;
//     int y;
// }node;

// int ans=0;
// int n,m,oc;
// int x1,y1,x2,y2;
// node ob[100];
// int fangxiang[5][2]={{0,0},{0,1},{0,-1},{1,0},{-1,0}};
// int visited[100][100]={0};
// void search(int w,int v){
//     if(w<1||w>n||v<1||v>m) return;
//     if(w==x2&&v==y2) {ans++;return;}
//     for(int i=1;i<=oc;i++){
//         if (w==ob[i].x&&v==ob[i].y)
//         {
//             return;
//         }
        
//     }
//     for(int i=1;i<=4;i++){
//         if(!visited[w+fangxiang[i][0]][v+fangxiang[i][1]]){
//             visited[w+fangxiang[i][0]][v+fangxiang[i][1]]=1;
//             search(w+fangxiang[i][0],v+fangxiang[i][1]);
//             visited[w+fangxiang[i][0]][v+fangxiang[i][1]]=0;
//             }
//     }
// }

// int main(int argc, char const *argv[])
// {
//     cin>>n>>m>>oc;
//     cin>>x1>>y1>>x2>>y2;
//     visited[x1][y1]=1;
//     for(int i=1;i<=oc;i++) cin>>ob[i].x>>ob[i].y;
//     search(x1,y1);
//     std::cout<<ans;
//     return 0;
// }

