#include "iostream"
#include "stdio.h"
#include "algorithm"
using namespace std;

void cheng(int a[],int b[]){
    int n1=a[0],n2=b[0];
    int c[100000]={0};
    c[0]=a[0]+b[0];
    if(c[0]>500) c[0]=500;
    for (int i =1; i <=c[0]; i++){
        for (int j =1; j <=i; j++){
            c[i]+=a[j]*b[i+1-j];
        if (c[i]>=10){
            c[i+1]+=c[i]/10;
            c[i]=c[i]%10;
    }}
}
    for (int i=0;i<=c[0];i++) a[i]=c[i];
}

int main(int argc, char const *argv[])
{
    int a[2000]={0};
    int n,s=0,i=2,ans[10000]={1,1,0};
    cin>>n;
    if (n<=4) {cout<<n<<endl<<n<<endl;return 0;}
    for (;s<=n;i++){s+=i;a[i]=i;}
    if(s-n==1){a[2]=0;a[i++]=0;a[i]=i;}
    else a[s-n]=0;
    for (int k = 2; k <=i; k++)
    {
        if(a[k]>0){ 
            cout<<a[k]<<' ';
            int x=a[k]%10,y=a[k]/10;
            int b[10000]={2,x,y,0};
            cheng(ans,b);
        }
    }
    while(ans[0]>1&&ans[ans[0]]==0) ans[0]--;
    cout<<endl;
    for(int j=ans[0];j>=1;j--) cout<<ans[j];
    return 0;
}