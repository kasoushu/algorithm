#include "bits/stdc++.h"
using namespace std;
void ans(){ 
    unordered_map<int,bool> a;
    int k;
    cin>>k;
    for(int i=0;i<k;i++){
        int p;
        cin>>p;
        if(!a[p]){
            printf("%d ",p);
            a[p]=1;
        }
    }
    cout<<endl;
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    while(n){ans();n--;}
    return 0;
}
