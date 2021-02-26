#include "bits/stdc++.h"

using namespace std;

struct que
{
    int left,right;
}a[10010];




int main(int argc, char const *argv[])
{
    int n,m;
    cin>>n;
    a[0].right=1;a[0].left=-1;
    a[1].left=0,a[1].right=-1;
    for(int i=2;i<=n;i++){
        int k,p;
        cin>>k>>p;
        if(p==0){           //左插入，使原来k左j节点的右为i，其右为i，并令k的左卫i
            a[i].right=k;
            a[i].left=a[k].left;
            a[a[k].left].right=i;
            a[k].left=i;
        }
        else if(p==1){
           //在k右插入,令原右的左卫i，k的右为i；
            a[i].left=k;
            a[i].right=a[k].right;
            a[a[k].right].left=i;
            a[k].right=i;
        }
    }
    cin>>m;
    int k;
    for(int i=1;i<=m;i++){
        cin>>k;
        //删除j即，令c的右的左为c。左，c的左的右为c的右;
        a[a[k].right].left=a[k].left;
        a[a[k].left].right=a[k].right;
        a[i].left=-1;
        a[i].right=-1;
    }
    // for( int i=0;i<=n;i++){
    //     // if(a[i].right==-1)break;
    //     cout<<a[i].left<<a[i].right<<' ';
    // }
   
    for(int i=0;1;i=a[i].right){
        if(a[a[i].right].right==-1){cout<<a[i].right<<endl;break;}
        cout<<a[i].right<<' ';
    }
    cout<<endl;
    return 0;
}
