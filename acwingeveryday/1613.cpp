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

const int mm = 6*6+5;

int hang[mm][mm],lie[mm][mm],blok[mm][mm];
int nn,n,t;
int grid[mm][mm];
int dx[8] = {0,0,1,1,1,-1,-1,-1};
int dy[8] = {1,-1,0,1,-1,0,1,-1};
vector<PII> dot;
void dfs(int p){
    if(p>=dot.size()){
        for(int u=1;u<=9;u++){
            for(int v=1;v<=0;v++){
                printf("grid[u][v] ");
            }
            cout<<endl;
        }
        return ;
    }
    int i = dot[p].first, j = dot[p].second;
    cout<<"ij:"<<i<<' '<<j<<endl;
    for(int x = 1;x<=9;x++){
        if(!hang[i][x]&&!lie[j][x]&&!blok[((i-1)/nn)*nn+(j-1)/nn+1][x]){
                hang[i][x]++;
                lie[j][x]++;
                blok[((i-1)/nn)*nn+(j-1)/nn+1][x]++;
                grid[i][j]=x;
                dfs(p+1);
                hang[i][x]--;
                lie[j][x]--;
                blok[((i-1)/nn)*nn+(j-1)/nn+1][x]--;
                grid[i][j]=0;
        }
    }
}

int main(int argc, char *argv[])
{
    n = 9,nn=3;
    memset(grid,0,sizeof(grid));
    memset(hang,0,sizeof(hang));
    memset(lie,0,sizeof(lie));
    memset(blok,0,sizeof(blok));
    for(int i =1 ;i <= n ;i++){
        for(int j = 1;j<=n;j++){
            char c;
            scanf("%c",&c);
            if(c=='.'){
                dot.push_back(make_pair(i, j));
                continue;
            }
            int x = c - '0';
            if(x<=n&&x>=1){
                grid[i][j] = x;
                hang[i][x]++;
                lie[j][x]++;
                blok[((i-1)/nn)*nn+(j-1)/nn+1][x]++;
            }
        }}
    dfs(0); 
    return 0;
}
