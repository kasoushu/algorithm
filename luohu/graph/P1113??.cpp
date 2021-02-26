#include "bits/stdc++.h"
#include "queue"
#include "vector"
using namespace std;

int n,m;
int ru[10005],ans[10005],wei[10005];
int ll[10005],vis[10005]={0};
vector<vector<int>> a;
vector<int> s;
int main(int argc, char const *argv[])
{
    cin>>n;
    a.resize(n+1);
    memset(ru,0,sizeof(ru));
    int x,w,ot;
    for(int i=1;i<=n;i++){
        scanf("%d%d",&x,&w);
        wei[x]=w;
        scanf("%d",&ot);
        while(ot!=0){
            ru[x]++;
            a[ot].push_back(i);
            scanf("%d",&ot);
        }
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(ru[i]==0){
            q.push(i);
            ans[i]=wei[i];
        }
    }
    while(!q.empty()){
        vector<int> fl;
        int k=q.front();
        q.pop();
        for(auto & j:a[k]){
            ru[j]--;
            if(ru[j]==0){
            q.push(j);
            }
            ans[j]=max(ans[j],ans[k]+wei[j]);
        }
   }
    // for(auto k:s){
    //     cout<<k<<' ';
    // }

    // for(int i=1;i<=n;i++){
    //     for(auto &p:a[i]){
    //         cout<<p<<' ';
    //     }
    //     cout<<endl;
    // }
    int an=0;
    for(int i=1;i<=n;i++){
        an=max(an,ans[i]);
    }
    cout<<an<<endl;
    return 0;
}
