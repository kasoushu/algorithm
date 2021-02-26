#include "iostream"
#include "iostream"

using namespace std;

int a[1005];

int find_x(int x){
    int p=x;
    while(a[p]!=p){
        p=a[p];
    }
    int y=x,k;
    while(a[y]!=y){k=a[y];a[y]=p;y=k;}
    return p;
}

void union_x(int x,int y){
    int i,j;
    i=find_x(x);
    j=find_x(y);
    if(i!=j) a[j]=i;
}


int get_res(int n){
    int cnt=0;
    int i;
    for(i=1;i<=n;i++){
        if(a[i]==i){
            cnt++;
        }
    }
    return cnt;
}


int main(int argc, char const *argv[])
{
    int n=1,m,i;
    while(n==0){
        cin>>n>>m;
        for( i=1;i<=n;i++) a[i]=i;
        for( i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        union_x(x,y);
    }
    //for(int i=1;i<=n;i++) cout<<a[i];
        cout<<get_res(n)-1<<endl;
    }
    return 0;
}