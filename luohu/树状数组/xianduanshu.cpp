#include "bits/stdc++.h"
#define MAX 1000001
#define ll long long


using namespace std;

unsigned ll n,m,a[MAX],ans[MAX<<2],tag[MAX<<2];

inline ll ls(ll x){
	return x<<1;
}
inline ll rs(ll x){
	return x<<1|1;
}

void scan(){
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
}

inline void push_up(ll p){
	ans[p]=ans[ls(p)]+ans[rs(p)];
}
void build(ll p,ll l,ll r){
    tag[p]=0;
    if(l==r){ans[p]=a[l];return ;}
    ll mid=(l+r)>>1;
    build(ls(p),l,mid);
    build(rs(p),mid+1,r);
    push_up(p);
}

inline void f(ll p,ll l,ll r,ll k){
    tag[p]=tag[p]+k;
    ans[p]=ans[p]+k*(r-l+1);
} 

inline void push_down(ll p,ll l,ll r){
    ll mid=(l+r)>>1;
    f(ls(p),l,mid,tag[p]);
    f(rs(p),mid+1,r,tag[p]);
    tag[p]=0;
}

inline void update(ll nl,ll nr,ll l,ll r,ll p,ll k){
    if(nl<=l&&r<=nr){
        ans[p]+=k;
        tag[p]+=k;
        return;
    }
    push_down(p,l,r);
    ll mid=(r+l)>>1;
    if(nl<=mid) update(nl,nr,l,mid+1,ls(p),k);
    if(nr>mid) update(nl,nr,mid,r,rs(p),k);
    push_up(p);
}

ll query(ll q_x,ll q_y,ll l,ll r,ll p){
	ll res=0;
	if(q_x<=l&&q_y>=r) return ans[p];
	ll mid=(l+r)>>1;
	push_down(p,l,r);
	if(q_x<=mid) res+=query(q_x,q_y,l,mid,ls(p));
	if(q_y>mid) res+=query(q_x,q_y,mid+1,r,rs(p));
	return res;
}


int main(int argc, char const *argv[])
{
	ll a1,b,c,d,e,f;
	scan();
	build(1,1,n);
	while(m--){
		scanf("%lld",&a1);
		switch(a1){
			case 1:{
				scanf("%lld%lld%lld",&b,&c,&d);
				update(b,c,1,n,1,d);
				break;
			}
			case 2:{
				scanf("%lld%lld",&e,&f);
				printf("%lld\n",query(e,f,1,n,1));
				break;
			}
		}
	}

    return 0;
}
