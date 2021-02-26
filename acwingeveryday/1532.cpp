#include "vector"
#include "bits/stdc++.h"
#include "map"
#include "queue"
#include "algorithm"
#include "stdio.h"
#include "iostream"
#include <unordered_map>
#include <utility>
#define ll long long
#define INF 0x3f3f3f3f
#define low_bit(x) ((x)&(-x))
using namespace std;

const int mm = 10005;
int a[mm];

int main(int argc, char *argv[])
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n);
    unordered_map<int,int> mp;
    for(int i=1;i<=n;i++){
        mp[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        if(mp.find(m-a[i])!=mp.end()&&mp[m-a[i]]!=i){
            cout<<a[i]<<' '<<m-a[i]<<endl;
            break;
        }
    }
    return 0;
}
