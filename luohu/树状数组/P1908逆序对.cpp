#include "bits/stdc++.h"
#define low_bit(x) ((x)&(-x))
#define NN 500005
using namespace std;
long long ans,n;
long long a[NN],b[NN],tr[NN];


bool cmp(long long &x,long long  &y){
	if(b[x]==b[y]) return x>y;
	else return b[x]>b[y];
}

void upd(int x){
	for(int i=x;i<=n;i+=low_bit(i)) tr[i]++;
}
long long query(int x){
	long long ans=0;
	for(int i=x;i;i-=low_bit(i)) ans+=tr[i];
	return ans;
}

int main(int argc, char const *argv[])
{
	cin>>n;

	for(int i=1;i<=n;i++) {scanf("%lld",&b[i]);a[i]=i;}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		upd(a[i]);
		ans+=query(a[i]-1);
	}
	cout<<ans;
	return 0;
}