#include "bits/stdc++.h"
using namespace std;
int a[10005];
int num[10005];
int find(int x){return x==a[x]?x:a[x]=find(a[x]);}

int main(int argc, char const *argv[])
{
    int n,m,p,ans;
    cin>>n>>m>>p;
    for(int i=0;i<=m;i++) a[i]=i;
    ans=m-n+1;    
    for(int i=2;i<=m;i++){
        if(!num[i]){
            if(i>=p){
                for(int j=2*i;j<=m;j+=i){
                    num[j]=1;
                    if(j-i>=n&&find(j)!=find(j-i)){
                        a[find(j)]=find(j-i);
                        ans--;
                        // cout<<?j<<' ';
                    }
                }

            }
            else{
                for(int j=i*2;j<=m;j+=i){
                num[j]=1;
            }
        }
        }

        


    }
    cout<<ans;
    return 0;
}
