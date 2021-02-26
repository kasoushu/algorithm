// #include "stdio"
#include "iostream"

using namespace std;
int v[100][5000]={0};

void gaoadd(int a[],int b[]){
    int len=a[0]+b[0];
    for ( int i = 1; i <=len+1; i++)
    {
        a[i]+=b[i];
        if(a[i]>=10){a[i+1]++;a[i]=a[i]%10;}
    }
    while(!a[len]) len--;
    a[0]=len;
}
//1000位高精减，第0位存储长度
//对于a-b>0的情况;
//c[i]=a[i]-b[i]如果<0则向上一位借位
// void gaosub(int a[],int b[],int ans[]){
//     int c[5000]={0};
//     int len=a[0]+b[0];
//     for (int i = 1; i <len; i++)
//     {
//         c[i]=c[i]+a[i]-b[i];
//         if(c[i]<0){a[i+1]--;c[i]+=10;}
//         // cout<<c[i]<<endl;
//     }
//     while(!c[len]) len--;
//     // cout<<len<<endl;
//     c[0]=len;
//     // for(int i=c[0];i>0;i--) cout<<c[i];
//     for(int i=0;i<=len;i++) ans[i]=c[i];
// }

int main(int argc, char const *argv[])
{
	int n,m;
	cin>>m>>n;
	v[0][0]=0,v[1][0]=1,v[1][1]=1;
	for(int i=2;i<=n;i++){
		gaoadd(v[i],v[i-1]);
		gaoadd(v[i],v[i-2]);
	}
	// if(m==1) for(int i=v[n][0];i>0;i--) cout<<v[n][i];
	// else
	// {
	for(int i=v[n-m+1][0];i>0;i--) cout<<v[n-m+1][i];
		// cout<<v[n]-v[m-1]-v[m-2]-1;
	// }
    return 0;
}
