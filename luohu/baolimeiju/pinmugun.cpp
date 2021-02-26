#include "algorithm"
#include "iostream"
#define ll long long
using namespace std;
const int MAX=1e6+10;
const long long mo=1e9+7;

int num[MAX]={0},n,v[MAX];

ll C(int a,int b){
    return b==1?a:a*(a-1)/2;
}

int main(int argc, char const *argv[])
{
    ll ans=0;
    int maxi=0;
    cin>>n;
    for(int i=0;i<n;i++){cin>>v[i];maxi=max(v[i],maxi);num[v[i]]++;}
    for (int i = 1; i <=maxi; i++){
        ll k=C(num[i],2)%mo;
        for (int x = 1; x <=i/2; x++) {
            if(x!=i-x) ans+=k*C(num[x],1)*C(num[i-x],1)%mo;
            if(x==i-x) ans+=k*C(num[x],2)%mo;
            ans%=mo;
        }
        
    }
    cout<<ans;
    return 0;
}
