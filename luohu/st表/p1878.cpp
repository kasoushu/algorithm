#include "vector"
#include "bits/stdc++.h"
#include "map"
#include "queue"
#include "algorithm"
#include "stdio.h"
#include <utility>
#include "iostream"
using namespace std;


vector< pair<int,int> >ans;
int n,q[1000005],cnt=0;
string s;
bool vis[1000005],f[1000005];


struct node{
  int x,y,z;
};

bool operator < (const node a,const node b){
  if(a.z == b.z){
		return a.x > b.x;
    }
	else
	{
		return a.z > b.z;
	}
}

priority_queue<node,vector<node> > pru;
int main(int argc, char *argv[])
{
 // pru.push((node){1,2,4});  
 //pru.push((node){1,2,5});
  cin>>n;
  cin>>s;
  for(int i=1;i<=n;i++){
    if(s[i-1]=='B') f[i]=1;
    else f[i]=0;
  }
  for(int i=1;i<=n;i++){
    scanf("%d",&q[i]);
  }
  for(int i=1;i<n;i++){
    if(f[i]!=f[i+1]){
      pru.push((node){i,i+1,abs(q[i+1]-q[i])});
    }
  }
  while(!pru.empty()){
    int x=pru.top().x;
    int y=pru.top().y;
    cout<<x<<' '<<y<<endl;
    pru.pop();
    if(vis[x]==0&&vis[y]==0){
      cnt++;
      vis[x]=1;vis[y]=1;
      ans.push_back(make_pair(x,y));
      while(x>0&&vis[x]!=0) x--;
      while(y<=n&&vis[y]!=0) y++;
      if(x>0&&y<=n&&f[x]!=f[y]){
        pru.push((node){x,y,abs(q[x]-q[y])});
      }
    }}
  // cout<<pru.top().z;
  cout<<cnt<<endl;
  for(auto k:ans){

    printf("%d %d\n",k.first,k.second);
  }
  return 0;
}
