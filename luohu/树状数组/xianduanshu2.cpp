// xianduanshu2.cpp
#include <bits/stdc++.h>
// #define ls(x) (x<<2)
// #define rs(x<<2|1)
using namespace std;

int p;
long long b[100007];

int rs(int x){
	return x<<1|1;
}
int ls(int x){
	return x<<1;
}

struct node{
	long long v,mul,add;
}a[400007];

void build(int root,int l,int r){
	a[root].mul=1;
	a[root].add=0;
	if(l==r) {a[root].v=b[l];}
	else{
		long long mid=(l+r)/2;
		build(ls(root),l,mid);
		build(rs(root),mid+1,r);
		a[root].v=(a[ls(root)].v+a[rs(root)].v)%p;
	}
	a[root].v%=p;
	return ;
}

void push_down(int root,int l,int r){
	int mid=(l+r)/2;
	a[ls(root)].v=(a[root].mul*a[ls(root)].v+a[root].add*(mid-l+1))%p;
	a[rs(root)].v=(a[root].mul*a[rs(root)].v+a[root].add*(r-mid))%p;
	a[ls(root)].mul=(a[root].mul*a[ls(root)].mul)%p;
	a[rs(root)].mul=(a[root].mul*a[rs(root)].mul)%p;
	a[ls(root)].add=(a[ls(root)].add*a[root].mul+a[root].add)%p;
	a[rs(root)].add=(a[rs(root)].add*a[root].mul+a[root].add)%p;
	a[root].mul=1;
	a[root].add=0;
	// a[root].v=(a[ls(root)]+a[rs(root)])%p;
	return ;
}
//乘
void up1(int root,int nx,int ny,int l,int r,long long k){
	if(r<nx||l>ny) return;
	if(r<=ny&&l>=nx) {
		a[root].v=(a[root].v*k)%p;
		a[root].mul=(k*a[root].mul)%p;
		a[root].add=(k*a[root].add)%p;
		return ;
	}

		int mid=(l+r)/2;
		push_down(root,l,r);
		up1(ls(root),nx,ny,l,mid,k);
		up1(rs(root),nx,ny,mid+1,r,k);
		a[root].v=(a[ls(root)].v+a[rs(root)].v)%p;
		return ;
}
//加
void up2(int root,int nx,int ny,int l,int r,long long k){
	if(r<nx||l>ny) return;
	if(r<=ny&&l>=nx) {
		a[root].v=(a[root].v+k*(r-l+1))%p;
		a[root].add=(k+a[root].add)%p;
		return ;
	}

		int mid=(l+r)/2;
		push_down(root,l,r);
		up2(ls(root),nx,ny,l,mid,k);
		up2(rs(root),nx,ny,mid+1,r,k);
		a[root].v=(a[ls(root)].v+a[rs(root)].v)%p;
		return ;
}

//query

long long query(int root,int q_x,int q_y,int l,int r){
	if(r<q_x||l>q_y) return 0;
	if(l>=q_x&&r<=q_y){
		return a[root].v;
	}
	push_down(root,l,r);
	int mid=(l+r)/2;
	return (query(ls(root),q_x,q_y,l,mid)+query(rs(root),q_x,q_y,mid+1,r))%p;
}








int main(int argc, char const *argv[])
{
int n, m;
    scanf("%d%d%d", &n, &m, &p);
    for(int i=1; i<=n; i++){
        scanf("%lld", &b[i]);
    }
    build(1, 1, n);
    while(m--){
        int chk;
        scanf("%d", &chk);
        int x, y;
        long long k;
        if(chk==1){
            scanf("%d%d%lld", &x, &y, &k);
            up1(1, x, y, 1, n, k);
        }
        else if(chk==2){
            scanf("%d%d%lld", &x, &y, &k);
            up2(1,x, y,1,n,k);
        }
        else{
            scanf("%d%d", &x, &y);
            printf("%lld\n", query(1, 1, n, x, y));
        }
    }

	return 0;
}