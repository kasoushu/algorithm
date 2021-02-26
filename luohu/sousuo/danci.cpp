#include "iostream"
#include "algorithm"
#include "string"
using namespace std;

string s="yizhong";
string a[100];

string search(string n){
	int k=n.size();
	int now=0;
	for(int i=0;i<k;i++){
		char c=n[i];
		bool flag=0;
		for(int j=now;j<8;j++){
			if(s[j]==c) {cout<<c;now=j+1;flag=1;}
		}
		if(flag==0) cout<<'*'; 
	}
	cout<<endl;
}


int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++) {cin>>a[i];search(a[i]);}
	// search("aaaaaaa");

	return 0;
}