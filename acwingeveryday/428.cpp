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

int k,n;

int main(int argc, char *argv[])
{
    cin>>k>>n;
    int res = 0;
    for(int i = 0 ;i < 22;i++){
        if(n>>i&1){
            int now = 1,t=i;
            while(t--){
                now*=k;
            }
            res+=now;
        }
    }
    cout<<res<<endl;
    return 0;
}
