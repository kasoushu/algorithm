// shudejisuan.cpp
#include "stdio.h"
#include "iostream"

using namespace std;
int f[1000]={1},n;
int main(int argc, char const *argv[])
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for (int j = 0; j <= i/2; ++j)
		{
			f[i]+=f[j];
		}
	cout<<f[n];
	return 0;
}