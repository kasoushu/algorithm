#include "iostream"
#include "algorithm"
#include "string.h"
#include "vector"
using namespace std;
char a[105][105];
int b[105][105];
int dx[9]={0, 0,1 ,1,1,0,-1,-1,-1};
int dy[9]={0,-1,-1,0,1,1, 1, 0,-1};
char s[]="yizhong";
vector< pair<int,int> > y_set;
int n,d=0;

bool dfs(int i,int j,int x,int y,int next){
    if(next>=6) {b[i][j]=1; return 1;}


    if(a[i][j]==s[next]&&dfs(i+x,j+y,x,y,next+1)) {b[i][j]=1;return 1;}
    return 0;
}


int main(int argc, char const *argv[])
{
    memset(b,0,sizeof(b));
    cin>>n;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) {cin>>a[i][j];if(a[i][j]=='y'){d++;y_set.push_back(make_pair(i,j));}} 
    
    while (d)
    {
        int i=y_set[d-1].first;
        int j=y_set[d-1].second;
        // cout<<"i="<<i<<' '<<j<<endl;
        for(int direct=1;direct<=8;direct++){
            // if(a[i+dx[direct]][j+dy[direct]]=='i'){
                // cout<<i<<' '<<j<<' '<<"dir"<<dx[direct]<<dy[direct]<<endl;
            // if(dfs(i+dx[direct],j+dy[direct],dx[direct],dy[direct],1)) {b[i][j]=1;cout<<i<<' '<<j<<' '<<"dir"<<dx[direct]<<dy[direct]<<endl;}
            if(dfs(i,j,dx[direct],dy[direct],0)) {b[i][j]=1;}
            // }
        }
        d--;
    }
    
    for(int i=1;i<=n;i++){
        for (int j = 1; j <=n; j++)
        {
            // cout<<b[i][j]<<' ';
            if(b[i][j]) cout<<a[i][j];
            else cout<<"*";

        }
        cout<<endl;
    }

    return 0;
}
