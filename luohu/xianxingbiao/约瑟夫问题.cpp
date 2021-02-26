#include "bits/stdc++.h"
using namespace std;
 
int main(){
    queue<int> a;
    int n,m,cnt=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        a.push(i);
    }
    while (!a.empty())
    {
        int p=a.front();
        a.pop();
        cnt++;
        if(cnt==m){cnt=0;cout<<p<<' ';}
        else a.push(p);
    }

    return 0;
}