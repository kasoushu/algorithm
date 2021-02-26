#include "vector"
#include "bits/stdc++.h"
#include "map"
#include "queue"
#include "algorithm"
#include "stdio.h"
#include "iostream"
#include <cstring>
#include <utility>
using namespace std;

const int mod = 100003;
const int N=1000009,M=2000009;
int head[N],to[M],nex[M],ans[N],dis[N];
int tot=0;
void add(int u,int v){
  tot++;
  to[tot]=v;
  nex[tot]=head[u];
  head[u]=tot;
}

int main(int argc, char *argv[])
{
  int n,m;
  int a,b;
  cin>>n>>m;
  //cout<<123;
  for(int i=0;i<m;i++){
    scanf("%d%d",&a,&b);
    add(a,b);
    add(b,a);
  }
  int vis[N];
  for(int i=1;i<=n;i++){
    vis[i]=0;
    dis[i]=0x3f3f3f3f;
    ans[i]=0;
  }
  dis[1]=0;
  ans[1]=1;
  priority_queue<pair<int, int> > qq;
  qq.push(make_pair(0,1));
  while(!qq.empty()){
    int p=qq.top().second;
    qq.pop();
    if(vis[p]) continue;
    vis[p]=1;
    for(int k=head[p];k;k=nex[k]){
      int i=to[k];
    //cout<<' '<<p<<' '<<i<<endl;
      if(dis[i]>dis[p]+1){
        dis[i]=dis[p]+1;
        ans[i]=ans[p];
        qq.push(make_pair(-dis[i],i));
      }else if(dis[i]==dis[p]+1){
        ans[i]+=ans[p];
        ans[i]%=mod;
      }
    }
  }

  for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
  return 0;

}
