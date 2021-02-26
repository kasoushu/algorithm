#include "vector"
#include "bits/stdc++.h"
#include "map"
#include "queue"
#include "algorithm"
#include "stdio.h"
#include "iostream"
#include <queue>
#include <utility>
#define ll long long
#define INF 0x3f3f3f3f
#define low_bit(x) ((x)&(-x))
#define PII pair<int,int> 
using namespace std;

const int mm = 1000;
int a[mm],d[mm],s[mm];
int n,t;

int main(int argc, char *argv[])
{
    cin>>n;
    memset(s,0,sizeof(s));
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&d[i]);
    }
    for(int i=2;i<=n;i++){
        scanf("%d",&s[i]);
        s[i]+=s[i-1];
    }
    cin>>t;
    int ans = 0;

    for(int i=1;i<=n&&s[i]<=t;i++){
        priority_queue<PII> q;
        for(int j=1;j<=i;j++) q.push(make_pair(a[j], d[j]));
        int r = t-s[i];
        int res=0;
        for(int j=1;j<=r;j++){
            int x = q.top().first,y=q.top().second;
            q.pop();
            if(x<=0) break;
            res+=x;
            q.push(make_pair(x-y, y));
        }
        ans=max(res,ans);
    }

    cout<<ans;
    return 0;
}
