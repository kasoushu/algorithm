#include <iostream> 
#include <algorithm> 
#include <vector>
#include <queue>
#include <map>
#include "cstring"
#define INF 0x3f3f3f3f
using namespace std;

int g[10000][10000]={0};
int visit[10000]={0};
int n,m;
void dfs(int root){
    // if(visit[root]==1) return;
    // visit[root]=1;
    printf("%d ",root);
    vector< int > a;
    for(int i=1;i<=n;i++){
        if(g[root][i]==1){
            a.push_back(i);
        }
    }
    sort(a.begin(),a.end());
    for(int i=0;i<a.size();i++){
        if(visit[a[i]]==0){
        visit[a[i]]=1;
        dfs(a[i]);}
    }
}

void bfs(int root){
    queue< int > a;
    a.push(root);
    visit[root]=1;
    // cout<<"enter bfs"<<endl;
    while(!a.empty()){
        int p=a.front();
        a.pop();
        cout<<p<<' ';
        for(int i=1;i<=n;i++){
            if(g[p][i]==1&&visit[i]==0){
                visit[i]=1;
                a.push(i);
            }
        }
        }
    // cout<<"quit bfs"<<endl;
}


int main(int argc, char const *argv[])
{
    // memset(g,0,sizeof(g));
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        g[x][y]=1;
    }
    memset(visit,0,sizeof(visit));
    dfs(1);
    memset(visit,0,sizeof(visit));
    cout<<endl;
    bfs(1);
    cout<<endl;
    return 0;
}
