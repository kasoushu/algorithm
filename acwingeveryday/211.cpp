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

int a,b,k,n,m;
const int mod = 10007;

int s[1005][1005]={0};

int pow(int x,int n){
    int ans = 1;
    while(n){
        if(n&1){
            ans=(ans*x)%mod;
        }
        x=x*x;
        n>>=1;
    }
    return ans;
}


int getans(int m,int n){
    for(int i=1;i<=n;i++){
        s[i][0]=s[i][i]=1;
        for(int j=1;j<=i>>1;j++){
            s[i][j]=s[i][i-j]=(s[i-1][j]+s[i-1][j-1])%mod;
        }
    }
    return s[n][m];
}



int main(int argc, char *argv[])
{
    cin>>a>>b>>k>>n>>m;
    cout<<getans(n,k)<<endl;
    return 0;
}
