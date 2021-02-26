// ziranshuchaifen.cpp
#include "iostream"
#include "algorithm"

using namespace std;

int ans=0,sum=0;
int a[100]={0},n;
void dfs(int q,int p){
	if(sum==n){
		for(int i=0;i<p-1;i++) cout<<a[i]<<'+';
		cout<<a[p-1]<<endl;
		return ;
	}
	if(sum>n) return;
	for(int i=q;i<n;i++){
		sum+=i;
		a[p] = i;
		dfs(i,p+1);
		a[p]=0;
		sum-=i;
	}

}


int main(int argc, char const *argv[])
{

	cin>>n;
	dfs(1,0);
	return 0;
}		