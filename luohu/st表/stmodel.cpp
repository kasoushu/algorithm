#include "iostream"
#include "stdio.h"
#include "bits/stdc++.h"
#include <cmath>
#define mm 200005
using namespace std;

int logg[mm]={0};
int a[100005]={0};
int st[100005][30]={0};
int n,m;
int qa,qb;

inline void pre(){
  logg[1]=0;
  for(int i=2;i<mm;i++){
    logg[i]=logg[i/2]+1;
  }
}

int main(){

  cin>>n>>m;
  for(int i=1;i<=n;i++){
    scanf("%d",&a[i]);
    st[i][0]=a[i];
  }
  pre();
  for(int k=1;k<=20;k++){
    for(int i=1;i+(1<<k)-1<=n;i++){
      st[i][k]=max(st[i][k-1],st[i+(1<<(k-1))][k-1]);  
  }
  }
  for(int i=1;i<=m;i++){
    scanf("%d%d",&qa,&qb);
    int qq;
    int len=qb-qa+1;
    qq=max(st[qa][logg[len]],st[qb-(1<<logg[len])+1][logg[len]]);
    printf("%d\n",qq);
  }
    return 0;
}
