#include "stdio.h"
#include "iostream"
#include "algorithm"

using namespace std;
int n,v[12],check[12]={0};
void printzuhe(){
    for(int i=1;i<=n;i++){
        printf("%5d",v[i]);
    }
    cout<<endl;
}
void dfs(int k){
    if (k==n){
        printzuhe();
        return ;
    }
    for(int i=1;i<=n;i++){
        if (!check[i]){
            check[i]=1;
            v[k+1]=i;
            dfs(k+1);
            check[i]=0;
        }
}}


int main(int argc, char const *argv[])
{
    cin>>n;
    dfs(0);
    return 0;
}
