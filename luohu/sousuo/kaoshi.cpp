#include "iostream"
#include "algorithm"
#include "cstdio"
using namespace std;
int s[5];
int minn,l,r;
int a[5][70];

void read(int s,int now[]){
    for(int i=0;i<s;i++) cin>>now[i];
}

void dfs(int x,int y){
    if(x>s[y]) { minn=min(minn,max(l,r));return;}
    l+=a[y][x];
    dfs(x+1,y);
    l-=a[y][x];
    r+=a[y][x];
    dfs(x+1,y);
    r-=a[y][x];
}

int find_time(int now[],int s){
    int sum=0;
    for(int i=1;i<s;i++){
        now[i]-=now[i-1];
    }
    for(int i=1;;i++){
        sum+=now[i];
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    int ans=0;
    for(int i=1;i<=4;i++) cin>>s[i];
    for(int i=1;i<=4;i++){
        for(int j=1;j<=s[i];j++) cin>>a[i][j];
        l=r=0;
        minn=0x7fffffff;
        dfs(1,i);
        ans+=minn;
    }
    cout<<ans;
    return 0;
}
