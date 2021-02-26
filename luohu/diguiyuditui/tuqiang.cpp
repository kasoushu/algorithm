#include "iostream"


using namespace std;

int d[1000000]={0};
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	d[1]=1;
	d[2]=2;
	for(int i=3;i<=n;i++){
		d[i]=2*d[i-1]%10000+d[i-2]%10000;
		d[i]%=10000;
	}
	cout<<d[n];
	return 0;
}