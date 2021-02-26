#include <algorithm> 
#include <vector>
#include <queue>
#include <map>
#include <string>
#include "iostream"
#define mod 80112002
using namespace std;

int ru[5005]={0},chu[5005]={0},f[5006]={0},n,m,ans=0;
bool g[5005][5005]={0};
int main(int argc, char const *argv[])
{
    cin>>n>>m;
    int a,b;
    for(int i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        g[a][b]=1;
        ru[b]++;
        chu[a]++;
    }   
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(ru[i]==0){
            f[i]=1;
            q.push(i);
        }
    }
    while(!q.empty()){
        int now=q.front();
        q.pop();
        for(int i=1;i<=n;i++){
            if(g[now][i]==0) continue;
            f[i]+=f[now];
            f[i]%=mod;
            ru[i]--;
            if(ru[i]==0){
                if(chu[i]==0){
                   ans+=f[i];
                   ans%=mod;
                    continue;
                }
                q.push(i);
            }
        }
    }
    cout<<ans;
    return 0;
}
