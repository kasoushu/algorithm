#include "vector"
#include "bits/stdc++.h"
#include "map"
#include "queue"
#include "algorithm"
#include "stdio.h"

using namespace std;

int n,m;
int dis[51][51],g[51][51][68];

void work(){
  
  for(int k=1;k<=64;k++){

    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        for(int t=1;t<=n;t++){
          if(g[i][t][k-1]&&g[t][j][k-1]){
            g[i][j][k]=1;
            dis[i][j]=1;
          }
        }
      }
    }
  }
}

int main(int argc, char *argv[])
{
  
  memset(g,0,sizeof(g));
  memset(dis,0x3f3f3f3f,sizeof(dis));
  cin>>n>>m;
  for(int i=1;i<=m;i++){

    int a,b;
    scanf("%d%d",&a,&b);
    dis[a][b]=1;
    g[a][b][0]=1;
  }
  work();
  for(int k=1;k<=n;k++){
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
      }
    }
  }
  printf("%d",dis[1][n]);
  return 0;
}
