#include "iostream"
#include "algorithm"
using namespace std;

int a[1000];

int find(int x){
    int p=x;
    while(a[p]!=p){p=a[p];}
    int y=x,t;
    while(a[y]!=y){t=a[y];a[y]=p;y=t;}
    return p;
}
void union_set(int x,int y){
    int i,j;
    i=find(x);
    j=find(y);
    if(i!=j){
        a[j]=i;
    }
    // return 0;
}

bool inquiry(int x,int y){
    int i,j;
    i=find(x);
    j=find(y);
    if(i==j) return 1;
    return 0;
}


int main(){
    int n,m,l;
    cin>>n>>m>>l;
    for(int i=1;i<=n;i++) a[i]=i;

    for(int i=0;i<m;i++){
        int x,t;
        cin>>x>>t;
        union_set(x,t);
    }
    for(int i=0;i<l;i++){
        int x,y;
        cin>>x>>y;
        if(inquiry(x,y)) cout<<"Yes"<<endl;
        else cout<<"NO"<<endl;
    }

}