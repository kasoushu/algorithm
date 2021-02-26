#include "iostream"
#include "algorithm"

using namespace std;

int ans=0x7fffffff,n;
int a[203]={0};//楼梯1-n
int d[2]={1,-1};
bool vis[203]={0};
int begin_p,end_p;
void dfs(int now,int t){
    if(t>ans ) return;
    if(now==end_p&&t<ans) ans=t;
    vis[now]=1;
    for(int i=0;i<2;i++){
        if(now+a[now]*d[i]>=1&&now+a[now]*d[i]<=n&&vis[now+a[now]*d[i]]==0) {dfs(now+a[now]*d[i],t+1);}
    }
    vis[now]=0;
    
}

int main(int argc, char const *argv[])
{
    cin>>n;
    cin>>begin_p>>end_p;
    for(int i=1;i<=n;i++) cin>>a[i];
    dfs(begin_p,0);
    cout<<(ans!=0x7fffffff?ans:-1);
    return 0;
}
