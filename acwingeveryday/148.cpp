#include "vector"
#include "bits/stdc++.h"
#include "map"
#include "queue"
#include "algorithm"
#include "stdio.h"
#include "iostream"
#include <queue>
#define ll long long
#define INF 0x3f3f3f3f
#define low_bit(x) ((x)&(-x))
#define PII pair<int,int> 
using namespace std;

const int mm = 10005;

int a[mm];
priority_queue<int,vector<int>,greater<int> > q;
int n;

int main(int argc, char *argv[])
{
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        q.push(a[i]);
    }
    ll ans = 0;
    while(q.size()>=2){
        int x = q.top();q.pop();
        int y = q.top();q.pop();
        ans+=(x+y);
        q.push(x+y);
    }
    cout<<ans<<endl;
    return 0;
}
