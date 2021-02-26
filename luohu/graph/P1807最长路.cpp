#include "bits/stdc++.h"
using namespace std;



int main(int argc, char const *argv[])
{
    int a[50001][3],dis[50001];
    // memset(dis,0,sizeof())
    memset(dis,0x3f3f3f3f,sizeof(dis));
    int n,m,u,v,w;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&u,&v,&w);
        a[i][0]=u,a[i][1]=v,a[i][2]=-w;
    }
    dis[1]=0;
    for(int i=1;i<=n-1;i++){
        for(int j=1;j<=m;j++){
            dis[a[j][1]]=min(dis[a[j][1]],dis[a[j][0]]+a[j][2]);
        }
    }
    
    printf("%d",dis[n]==0x3f3f3f3f?-1:-dis[n]);
    return 0;
}
