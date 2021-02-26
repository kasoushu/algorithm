#include "algorithm"
#include "iostream"
using namespace std;

int main(int argc, char const *argv[]){
	int a[10000],n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	while(m){next_permutation(a,a+n);m--;}
	for(int i=0;i<n;i++) cout<<a[i]<<' ';
	return 0;
}