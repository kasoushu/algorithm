#include "bits/stdc++.h"
using namespace std;



int main(int argc, char const *argv[])
{
    int n,q,x,y,z;
    cin>>n>>q;
    map<int,int> a[10005];
    for(int i=0;i<q;i++){
        cin>>x;
        if(x==1){
            cin>>x>>y>>z;
            a[x][y]=z;
        }
        if(x==2){
            cin>>y>>z;
            if(a[y][z]!=0) cout<<a[y][z]<<endl;
        }
    }
    return 0;
}
