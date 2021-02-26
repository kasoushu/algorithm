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
using namespace std;

const int mm = 30;

int lie[mm],l_h[mm],r_h[mm];
int n;
int res=0,pth[mm];

void dfs(int r){
    if(r>n){
        res++;
        if(res<=3){

        for(int i=1;i<=n;i++){
            printf("%d ",pth[i]);
        }
        cout<<endl;
        }
    }
    
    for(int i=1;i<=n;i++){
        if(!lie[i]&&!l_h[r+i-1]&&!r_h[r-i+1]){
            pth[r]=i;
            lie[i]=l_h[r+i-1]=r_h[r-i+1]=1;
            dfs(r+1);
            lie[i]=l_h[r+i-1]=r_h[r-i+1]=0;
        }
    }

}


int main(int argc, char *argv[])
{
    cin>>n;
    dfs(1);
    cout<<res;
    return 0;
}
