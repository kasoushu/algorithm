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

int n,a,ans=0;

int main(int argc, char *argv[])
{
    cin>>n;
    int now=0;
    for(int i=1;i<=n;i++){
        cin>>a;
        if(a>now) ans+=a-now;
        now=a;
    }
    cout<<ans<<endl;
    return 0;
}
