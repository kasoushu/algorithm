#include "iostream"
#include "algorithm"
#include "string"
typedef unsigned long long ull;
using namespace std;
int n,ans;
ull base=131;
ull a[100010];
ull mod=19260817;

ull get_hash(string s){
    int l=s.size();
    ull p=0;
    for(int i=0;i<l;i++){
        p=(p*base+(ull)s[i])%mod;
    }
    return p;
}

bool check(ull hash_v){
    ull p=hash_v;
    for(int i=1;i<=n;i++){
        if(a[i]==p) return false;
    }
    return true;
}   

int main(int argc, char const *argv[])
{
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++){
        string now_string;
        cin>>now_string;
        ull p=get_hash(now_string);
        while(!check(p)) p+=233317;
        a[i]=p;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(a[i]!=a[i+1]) ans++;
    }
    cout<<ans;
    return 0;
}
