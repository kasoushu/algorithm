#include "iostream"
#include "algorithm"

using namespace std;

int a[100005]={0};
int len[100005]={0},q[100005]={0};
long long  n;
int main(int argc, char const *argv[])
{
    int min=0x7fffffff;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    int q_num=0;
    for(int i=0;i<n;i++){
        // sum++;
        // if(a[i+1]-a[i]!=1) {k=i;if(sum<min) min=sum;sum=0;}
        // if(a[i+1]==a[i]) {k=i;if(sum<min) min=sum;sum=0;}
        int max=0x7fffffff;
        int k=0,find=0;
        for(int j=1;j<=q_num;j++){
            if(q[j]+1==a[i]&&len[j]<max){k=j,max=len[j];find=1;}
        }


        if(!find){
            q[++q_num]=a[i];
            len[q_num]++;
        }else
        {
            q[k]=a[i];
            len[k]++;   
        }
    }
    for(int i=1;i<=q_num;i++) if(len[i]<min) min=len[i];
    // for(int i=1;i<=q_num;i++) cout<<len[i]<<endl;
    cout<<min;
    return 0;
}
