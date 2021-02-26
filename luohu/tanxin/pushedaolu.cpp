// pushedaolu.cpp
#include "iostream"
#include "algorithm"

using namespace std;
int a[100000]={0};
int sum=0,n;
int result(int left,int right){
	int now=0;
	if(left>right) return 0;
	else if(left==right) return a[left];
	int min=0x7fffffff,x;
	for(int i=left;i<=right;i++){
		if(a[i]<min) {min=a[i];x=i;}
	}
	now+=min;
	for(int i=left;i<=right;i++){
		a[i]-=min;
	}
	now+=result(left,x-1);
	now+=result(x+1,right);
	return now;
}



int main(int argc, char const *argv[])
{
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	sum=result(0,n-1);
	cout<<sum;
	return 0;
}