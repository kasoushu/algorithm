#include <iostream> 
#include <algorithm> 
#include <vector>
#include "deque"
#include "stdio.h"
#include "bits/stdc++.h" 
using  namespace std;

struct node
{
    int pos,val;
    /* data */
}v[1000005];

deque<node>  a;
deque<node>  b;
int ans[1000005]={0};
int an[1000005]={0};
int n,k;

int main(int argc, char const *argv[])
{
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        scanf("%d",&v[i].val);
        v[i].pos=i;
    }
    //min
    for(int i=1;i<=n;i++){
        while(!a.empty()&&a.back().val>v[i].val) a.pop_back();
        a.push_back(v[i]);
        while(a.front().pos<=i-k) a.pop_front();
        if(i>=k) ans[i]=a.front().val;
        // cout<<i<<endl;
    }
    // cout<<111;
    for(int i=k;i<=n;i++){
        cout<<ans[i]<<' ';
    }
    for(int i=1;i<=n;i++){
        while(!b.empty()&&b.back().val<v[i].val) b.pop_back();
        b.push_back(v[i]);
        while(b.front().pos<=i-k){b.pop_front();}
        if(i>=k) an[i]=b.front().val;
        // cout<<b.back().val<<' '<<b.front().val<<endl;
    }
    cout<<endl;
    for(int i=k;i<=n;i++){
        cout<<an[i]<<' ';
    }

    return 0;
}