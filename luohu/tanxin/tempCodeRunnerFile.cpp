#include "iostream"
#include "algorithm"

using namespace std;

int a[100000]={0};
int len[100000]={0},q[100000]={0};
long long  n,sum=0;
int main(int argc, char const *argv[])
{
    int min=0x7fffffff;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    int k=0;
    int q_num=0;
    for(int i=0;i+1<n;i++){
        // sum++;
        // if(a[i+1]-a[i]!=1) {k=i;if(sum<min) min=sum;sum=0;}
        // if(a[i+1]==a[i]) {k=i;if(sum<min) min=sum;sum=0;}
        int max=0x7fffffff;
        int k=-1;
        for(int j=0;j<=q_num;j++){
            if(q[j]+1==a[i]&&len[j]<max){k=j,max=len[j];}
        }
        if(k>-1){
            q[k]=a[i];
            len[k]++;
        }else
        {
            q[++q_num]=a[i];
            len[q_num]++;
        }
    }
    for(int i=0;i<=q_num;i++) if(len[i]<min) min=len[i];
    cout<<min;
    return 0;
}
