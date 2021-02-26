#include <iostream> 
#include <algorithm> 
#include <vector>
 
using  namespace std;
const int maxN = 100005;
int n,m,ans=0,a[3*maxN];

int find(int x){ return a[x]==x?x:a[x]=find(a[x]);}
int main(int argc, char const *argv[])
{
    cin>>n>>m;
    for(int i=1;i<=3*n;i++) a[i]=i;
    while(m--){
        int opt,x,y;
        scanf("%d%d%d",&opt,&x,&y);
        if(x>n||y>n) ans++;
        if(opt==1){
            if(find(x+n)==find(y)||find(x)==find(y+n)) ans++;
            else{
                a[find(x)]=find(y);
                a[find(n+x)]=find(y+n);
                a[find(x+n+n)]=find(y+n+n);
            }
        }
        else{
            if(x==y) ans++;
            else if(find(x)==find(y)||find(x)==find(y+n)) ans++;
            else{
                a[find(x+n)]=find(y);
                a[find(x+n+n)]=find(y+n);
                a[find(x)]=find(y+n+n);}
        }
    }
    cout<<ans<<endl;
    return 0;
}