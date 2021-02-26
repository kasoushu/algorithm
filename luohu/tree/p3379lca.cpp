#include "vector"
#include "bits/stdc++.h"
#include "map"
#include "queue"
#include "algorithm"
#include "stdio.h"
#include "iostream"
#include <cstdio>
using namespace std;
struct node{
  int v,nex;
}e[800000];
int h[500005],lg[500005],deep[500005],fa[500006][30];
int t=0;
int n,m,s;
void pre(){
  memset(h,0,sizeof(h));
  memset(lg,0,sizeof(lg));
  memset(deep,0,sizeof(deep));
  memset(fa,0,sizeof(fa));
  lg[1]=0;
  for(int i=2;i<=n;i++){
    lg[i]=lg[i/2]+1;
    cout<<"log"<<i<<" "<<lg[i]<<' ';
  }
}

void add(int x,int y){
  e[++t].v=y;
  e[t].nex=h[x];
  h[x]=t;
}

void dfs(int now,int fr){
  fa[now][0]=fr;deep[now]=deep[fr]+1;
  for(int i=1;i<=lg[deep[now]];i++){
    fa[now][i] = fa[fa[now][i-1]][i-1];
  }
  for(int i=h[now];i;i=e[i].nex){
    if(e[i].v!=fr) dfs(e[i].v,now);
    
  }
}

int lca(int x,int y){
  if(deep[x]<deep[y]){
  swap(x,y);}
  while(deep[x]>deep[y]) {x=fa[x][lg[deep[x]-deep[y]]];}
  if(x==y) return x;
  for(int k=lg[deep[x]]-1;k>=0;--k){
    if(fa[x][k]!=fa[y][k]) {x=fa[x][k];y=fa[y][k];}
  }
  return fa[x][0];
}
int main(int argc, char *argv[])
{
  scanf("%d%d%d",&n,&m,&s);
  pre();
  for(int i=1;i<=n-1;++i){
    int x,y;
    scanf("%d%d",&x,&y);
    add(x,y);add(y,x);
  }
  //cout<<"hello";
  dfs(s,0);
  for(int i=0;i<10;i++){
    // cout<<i<<"      "<<fa[i][0]<<"  et  "<<e[i].v<<' '<<e[i].nex<<"  h  "<<h[i]<<endl;
  }
  for(int i=1;i<=m;i++){
    int x,y;scanf("%d%d",&x,&y);
    printf("%d\n",lca(x, y));
  }
  return 0;
}
