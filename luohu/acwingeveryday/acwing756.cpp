#include "vector"
#include "bits/stdc++.h"
#include "map"
#include "queue"
#include "algorithm"
#include "stdio.h"
#include "iostream"
#define ll long long
#define ui unsigned int
#define INF 0x3f3f3f3f
#define low_bit(x) ((x)&(-x))

typedef std::pair<int,int> pii;
using namespace std;

int n,m;
int a[200][200]={0};
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

void dfs(int x,int y,int num,int ta,int tb){
    if(a[x][y]) return;
    if(num>n*m) return;
    a[x][y]=num;
    int na=x+ta,nb=y+tb;
    if(na>=1&&na<=n&&nb>=1&&nb<=m&&a[na][nb]==0){
        dfs(na,nb,num+1,ta,tb);
    }else{
        for(int i=0;i<4;i++){
            int na=x+dx[i],nb=y+dy[i];
            if(na>=1&&na<=n&&nb>=1&&nb<=m&&a[na][nb]==0){
                dfs(na, nb, num+1,dx[i],dy[i]);
            }
        }
    } 
}
int main(int argc, char *argv[])
{
    cin>>n>>m;
    dfs(1,1,1,0,1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) cout<<a[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}
