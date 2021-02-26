#include "bits/stdc++.h"
#define low_bit(x) ((x)&(-x))
using namespace std;
int a[10000]={0};
//update a[i]->j;
void update(int i,int j){
    for(int p=i;i<100;p+=low_bit(p)){a[p]+=j;}
}

int query(int x){
    int ans=0;
    for(int p=x;p;p-=low_bit(p)) ans+=a[p];
    return ans;
}

int main(int argc, char const *argv[])
{

    for(int i=1;i<2;i++){
        update(i,1);
    }    
    cout<<query(9);    
    return 0;
}




