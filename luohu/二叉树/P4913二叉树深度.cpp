#include "bits/stdc++.h"

using namespace std;
struct node{
    int left,right;
}a[1000000];

int dfs(int root,int deep){
    if(a[root].left==0&&a[root].right==0) return deep+1;   
    int dl=dfs(a[root].left,deep+1);
    int dr=dfs(a[root].right,deep+1);
    return max(dl,dr);
}


int main(int argc, char const *argv[])
{
    int n,x,y;
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d%d",&x,&y);
        a[i].left=x;
        a[i].right=y;
    }
    cout<<dfs(1,0);
    return 0;
}
