#include "iostream"
#include "algorithm"

using namespace std;

typedef struct
{
    int high;
    int s;
}apple;
//dingyi;
apple a[50005];
int n,s,b,ch;

bool cmp(apple a,apple b){
    return a.s<b.s?1:0;
}

int main(int argc, char const *argv[])
{
    cin>>n>>s;
    cin>>ch>>b;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        a[i].high=x;
        a[i].s=y;
    }
    sort(a,a+n,cmp);
    int sum=0,load=0;
    for(int i=0;i<n;i++){
        if(b+ch>=a[i].high&&load+a[i].s<=s) {sum++;load+=a[i].s;}
    }
    // for(int i=0;i<n;i++) cout<<a[i].s<<' ';
    cout<<sum;
    return 0;
}
