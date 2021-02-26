#include "bits/stdc++.h"
using namespace std;
int a[1005];
int en[1005]={0};
int n,m;

int find(int x){return x==a[x]?x:a[x]=find(a[x]);}
void union_set(int x,int y){x=find(x),y=find(y); if(x!=y) a[x]=y;}

int main(int argc, char const *argv[])
{
    char c;
    int x,y;
    cin>>n>>m;
    for(int i=0;i<=n;i++) a[i]=i;
    for(int i=0;i<m;i++){
        cin>>c>>x>>y;
        if(c=='F'){
            union_set(x,y);
        }
        else if(c=='E'){
            if(!en[x]) en[x]=y;
            else {
                union_set(find(en[x]),y);
            }
            if(!en[y]) en[y]=x;
            else
            {
                union_set(find(en[y]),x);
            }
            
        }

    }

    int cnt=0;
    for(int i=1;i<=n;i++) if(a[i]==i) cnt++;
    cout<<cnt;
    return 0;
}

