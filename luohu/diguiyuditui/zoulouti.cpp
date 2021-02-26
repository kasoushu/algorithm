#include "stdio.h"
#include "iostream"

using namespace std;
int n,ans=0;
int a[5000][5000]={0};
void zoulouti(int k){
    if(k==n){ ans++;return;}
    if(k>n) return;
    zoulouti(k+1);
    zoulouti(k+2);
    return;
}


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
void gaosub(int a[],int b[],int ans[]){
    int c[1000]={0};
    int len=a[0]+b[0];
    for (int i = 1; i <len; i++)
    {
        c[i]=c[i]+a[i]-b[i];
        if(c[i]<0){a[i+1]--;c[i]+=10;}
        // cout<<c[i]<<endl;
    }
    while(!c[len]) len--;
    // cout<<len<<endl;
    c[0]=len;
    // for(int i=c[0];i>0;i--) cout<<c[i];
    for(int i=0;i<=len;i++) ans[i]=c[i];
}


void ditui(int n){
    a[0][0]=1,a[1][0]=1;
    a[0][1]=1,a[1][1]=1;
    // for(int j=a[1][0];j>=0;j--) cout<<a[1][j];
    for(int i=2;i<=n;i++){
        // cout<<"di tui zhong "<<endl;
        gaoadd(a[i],a[i-1]);
        // cout<<endl;
        gaoadd(a[i],a[i-2]);
        // for(int j=a[i][0];j>0;j--) cout<<a[i][j];
        // cout<<"ditui jieshu"<<endl;
    }
}
// int main(int argc, char const *argv[])
// {
//     cin>>n;
//     // int b[2][1000]={{1,1,0},{0}};
//     // int c[2][1000]={{1,1,0},{0}};
//     ditui(n);  
//     // gaoadd(b[0],c[0]);
//     // for(int i=20;i>=0;i--) cout<<a[n+1][i];
//     for(int i=a[n][0];i>0;i--) cout<<a[n][i];
//     return 0;
// }


int main(int argc, char const *argv[])
{
    int ans[1000]={0};
    int a[1000]={4,4,3,2,1,0},b[1000]={4,0,0,0,1,0};
    // for(int i=20;i>0;i--) cout<<ans[i];
    gaosub(a,b,ans);
    // cout<<ans[0]<<endl;
    for(int i=ans[0];i>0;i--) cout<<ans[i];
    return 0;
}
