#include "vector"
#include "bits/stdc++.h"
#include "map"
#include "queue"
#include "algorithm"
#include "stdio.h"
#include "iostream"
#define ll long long
#define INF 0x3f3f3f3f
#define low_bit(x) ((x)&(-x))
using namespace std;

const int mm = 100005;
const int mn = 10005;

int a[mm][26]={0},tag[mm]={0},tot=0,n,m;

void insert(string s){
    int len = s.size();
    int u=1;
    for(int i=1;i<=len;i++){
        int c = s[i-1]-'a';
        if(!a[u][c]) a[u][c]=++tot;
        u=a[u][c];
    }
    tag[u] = 1;
    cout<<"insert  "<<s<<' '<<tag[u]<<' '<<u<<endl;
}


int main(int argc, char *argv[])
{
    cin>>n;
    string s;
    for(int i=1;i<=n;i++){
        cin>>s;
        insert(s);
    }
    cin>>m;
    for(int i=1;i<=m;i++){
        cin>>s;
        int len = s.size();
        int p=1,ans=0;
        for(int i=1;i<=len;i++){
            int c=s[i-1]-'a';
            if(!a[p][c]) break;
            p=a[p][c];
        }
        ans=tag[p];
        cout<<s<<' '<<ans<<endl;
        if(ans==0) printf("WRONG\n");
        else if(ans==1){
            printf("OK\n");
            tag[p]=2;
        }else if(ans>1){
            printf("REPEAT\n");
        }
    }
    return 0;
}
