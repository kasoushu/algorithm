/*
 * @Author: @Katwo 
 * @Date: 2020-11-23 20:37:04 
 * @Last Modified by: @Katwo
 * @Last Modified time: 2020-11-23 21:45:05
 */
#include <iostream> 
#include <algorithm> 
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int n,width=0,deep=0;
struct node
{
    int p,l,r;
}a[105];

int f[105]={0},dp[105]={0},l[105]={0};
// int dfs(int root){
//     int i=0,j=0;
//     if(a[root].l>0){
//         i=dfs(a[root].l)+1;
//     }
//     if(a[root].r>0){
//         j=dfs(a[root].r)+1;
//     }
//     return max(i,j)+1;
// }
// int find(int p){
//     return a[p].p;
// }

// int get_path(int p1,int p2){
//     int x=0,y=0;
//     while(a[p1].p!=a[p2].p){
//         p1=a[p1].p;x++;
//         p2=a[p2].p;y++;
//     }
//     return x*2+y;
// }
// void bfs(int root){
//     queue<int> q;
//     q.push(root);
//     while(!q.empty()){
//         vector<int> k;
//         while(!q.empty()){
//             k.push_back(q.front());
//             q.pop();
//         }
//         int len=k.size();
//         width=max(width,len);
//         for(auto &i:k){
//             cout<<i<<' ';
//             if(a[i].l) q.push(a[i].l);
//             if(a[i].r) q.push(a[i].r);
//         }
//         cout<<endl;
//     }
// }
int lcnt=0,rcnt=0;

void find(int p1,int p2){
    if (p1==p2){
        cout<<(lcnt*2+rcnt);
        return;
    }
    if(dp[p1]==dp[p2]){lcnt++;rcnt++;find(f[p1],f[p2]);}
    else if(dp[p1]>dp[p2]){lcnt++;find(f[p1],p2);}
    else {rcnt++;find(p1,f[p2]);}
    return ;
}


int main(int argc, char const *argv[])
{
    cin>>n;
    int k,d;
    dp[1]=1;
    for(int i=1;i<=n-1;i++){
        scanf("%d%d",&k,&d);
        f[d]=k;
        dp[d]=dp[k]+1;
        deep=max(deep,dp[d]);
        l[dp[d]]++;   
        width=max(width,l[dp[d]]);
    }
    scanf("%d%d",&k,&d);
    cout<<deep<<endl<<width<<endl;
    find(k,d);
    return 0;
}
