#include "vector"
#include "bits/stdc++.h"
#include "map"
#include "queue"
#include "algorithm"
#include "stdio.h"
#include "iostream"
#define ll long long
#define INF 0x3f3f3f3f
#define low_bit(x) ((x)&(-x))
#define PII pair<int,int> 
using namespace std;

const int mm = 105;

int g[mm][mm];
int n,m,k;

void dp(){
    for(int i = 1;i<=n;i++){
        for(int j =1;j<=m;j++){
            g[i][j]+=max(g[i-1][j],g[i][j-1]);
        }
    }
}

int main(int argc, char *argv[])
{
    cin>>k;
    while(k--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            for(int j =1 ;j<=m;j++){
                scanf("%d",&g[i][j]);
            }
        }
        dp();
        printf("%d\n",g[n][m]);
    }
    return 0;
}
