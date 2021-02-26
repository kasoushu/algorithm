#include "stdio.h"
#include "iostream"
#include "algorithm"
#include "cmath"
using namespace std;
long long n,s[10],b[10],ans=0x7fffffff;

void dfs(int k,long long sour,long long bitter){
    if (k==n){
        if(sour==1&&bitter==0) return;
        ans=min(ans,abs(sour-bitter));
        return;
    }

    dfs(k+1,sour*s[k],bitter+b[k]);
    dfs(k+1,sour,bitter);
    
}


int main(int argc, char const *argv[])
{
    cin>>n;
    for(int i=0;i<n;i++) cin>>s[i]>>b[i];
    dfs(0,1,0);
    cout<<ans;
    return 0;
}
