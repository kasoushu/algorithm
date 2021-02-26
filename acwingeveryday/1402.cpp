#include "vector"
#include "bits/stdc++.h"
#include "map"
#include "queue"
#include "algorithm"
#include "stdio.h"
#include "iostream"
#include <vector>
#define ll long long
#define INF 0x3f3f3f3f
#define low_bit(x) ((x)&(-x))
#define PII pair<int,int> 
using namespace std;

const int mm = 150;

char g[mm][mm],n,m;
map<double , char > ma;
vector<PII> v;
int dx[8] = {0,0,1,1,1,-1,-1,-1};
int dy[8] = {1,-1,0,-1,1,-1,0,1};

void dfs(int x,int y){
    g[x][y]='0';
    v.push_back(make_pair(x,y));
    for(int i =0;i<8;i++){
        int nx=x+dx[i],ny=y+dy[i];
        if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&g[nx][ny]=='1'){
            dfs(nx,ny);
        }
    }
}
char build_map(){
    int len = v.size();
    double sum = 0;
    for(int i=0;i<len;i++){
        for(int j=i+1;j<len;j++){
            sum+=sqrt((v[i].first-v[j].first)*(v[i].first-v[j].first)+(v[i].second-v[j].second)*(v[i].second-v[j].second));
        }
    }
    for(auto &[k,v]:ma){
        if(abs(k-sum)<1e7){
            return v;
        }
    }
    char c= 'a'+ma.size();
    ma[sum] = c;
    return c;
}
void draw(char c){
    for(auto &k:v){
        g[k.first][k.second] = c;
    }
}
int main(int argc, char *argv[])
{
    cin>>n>>m;
    cout<<n<<m<<endl;
    for(int i=1;i<=n;i++) for(int j =1;j<=m;j++) cin>>g[i][j];
    cout<<123;
    for(int i =1 ;i<= n ;i++){
        for(int j =1 ;j<=m;j++){
            printf("%c",g[i][j]);
        }
        cout<<endl;
    }
    for(int i =1 ;i<= n;i++){
        for(int j=1;j<=m;j++){
            dfs(i,j);
            char c = build_map();
            draw(c);
            v.clear();
        }
    }
    return 0;
}
