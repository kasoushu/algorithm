//洛谷P4588
#include "bits/stdc++.h"
using namespace std;

int t,n;
long long a[400001];
const long long mod;
void build(int n){
	memset(a,1,sizeof(a));
}
void ud(int p,int m,int pos,int l,int r){
	if(l==r){a[p]=m;return;}
	int mid=(l+r)>>1;
	if(pos<=mid) ud(p<<1,m,pos,l,mid);
	else ud(p<<1 | 1,m,pos,mid+1,r); 
	a[p]=(a[p<<1]*a[p<<1|1])%mod;
}



int main(int argc, char const *argv[])
{
	scanf("%d",&t);
	while(t--){
		scanf("%d%lld",&n,&mod);
		build(n);
		int ins,m;
		for(int i=1;i<=n;i++){
			scanf("%d%d",&ins,&m);
			if(ins==1){
				ud(1,m,i,1,n);
				printf("%d\n",a[1]);
			}
			else if(ins==2){
				ud(1,1,i,1,n);
				printf("%d\n",a[1]);
			}
		}



	}
	return 0;
}