#include "iostream"
#include "stdio.h"
#include "algorithm"
#define uul unsigned long long

using namespace std;

int n,m,ans=0,a,b;

uul f[30][30]={0};
int fx[]={0,2,1,-1,-2,-2,-1,1,2};
int fy[]={0,1,2,2,1,-1,-2,-2,-1};
int check[30][30]={0};


int main(int argc, char const *argv[]){
    cin>>n>>m>>a>>b;
    n+=2,m+=2,a+=2,b+=2;
    f[2][2]=1;
    check[a][b]=1;
    for (int i = 1; i <=8 ; ++i){
    	check[a+fx[i]][b+fy[i]]=1;
    }
    for(int i=2;i<=n;i++){
    	for(int j=2;j<=m;j++){
    		if(check[i][j]) continue;
    		f[i][j] =max(f[i][j],f[i-1][j]+f[i][j-1]);
    	}
    }
    // for(int i=0;i<30;i++){
    //     for(int j=0;j<30;j++) cout<<check[i][j]<<' ';
    //     cout<<endl;
    // }
    cout<<f[n][m];
    return 0;
}
