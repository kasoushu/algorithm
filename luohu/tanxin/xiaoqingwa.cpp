#include "iostream"
#include "algorithm"
#include "cmath"
using namespace std;
int n;
int a[305]={0};
int visit[305]={0};
int main(int argc, char const *argv[])
{
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    int max=0,lastmax=0;
    long long sum=0;
    for (int i = 0; i < n; i++){
        max=0;
        int cha=0;
        int k;
        for(int j=0;j<n;j++){
            if(std::abs(a[j]-lastmax)>cha&&visit[j]==0) {max=a[j];cha=std::abs(max-lastmax);k=j;}
        }
        visit[k]=1;
        sum+=std::abs(max-lastmax)*std::abs(max-lastmax);
        lastmax=max;
    }
    cout<<sum;    
    return 0;
}
