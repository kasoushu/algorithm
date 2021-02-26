#include "vector"
#include "bits/stdc++.h"
#include "map"
#include "queue"
#include "algorithm"
#include "stdio.h"
#include "iostream"
#include <utility>
#define ll long long
#define INF 0x3f3f3f3f
#define low_bit(x) ((x)&(-x))
#define PII pair<int,int> 
using namespace std;

const int mm = 10005;

int t,n;
int a[mm];


int main(int argc, char *argv[])
{
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        vector<PII> q;
        for(int i=1;i+1<=n;i++){
            if((max(a[i],a[i+1])*1.0)/min(a[i],a[i+1])>2){
                q.push_back(make_pair(min(a[i],a[i+1]),max(a[i],a[i+1])));
            }
            }
        int cnt=0;
        for(auto &k:q){
            // cout<<k.first<<' '<<k.second<<endl;
            int x=k.first,y=k.second;
            while(y*1.0/x > 2){
                x=x*2;
                cnt++;
            }
            }
        cout<<cnt<<endl;
    }
    return 0;
}
