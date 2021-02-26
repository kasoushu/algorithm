
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

const int mm = 100000;
char s[mm];
int pi[mm]={0};


int nex(int n){
        for(int i=1;i<n;i++){
            int j=pi[i];
            while(j&&s[j+1]!=s[i+1]) j=pi[j];
            pi[i+1]=s[j+1]==s[i+1]?++j:j;
        }
    // for(int i=1;i<=n;i++) cout<<pi[i]<<' ';
    // cout<<endl;
    return 0;
}


int main(int argc, char *argv[])
{
    int n,ans=0;
    cin>>n;
    cin>>(s+1);
    nex(n);
    for(int i=2;i<=n;i++){
        int k=i;
        while(pi[k]>0) k=pi[k];
        if(pi[i]>0){
            pi[i]=k;
        }
        ans+=i-k;
        // for(int l=1;l<=n;l++) cout<<pi[l]<<' ';
        // cout<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
