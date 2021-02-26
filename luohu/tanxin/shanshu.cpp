#include "algorithm"
#include "iostream"

using namespace std;
int a[260]={0};
int k;
int main(int argc, char const *argv[])
{
    string s;
    cin>>s;
    cin>>k;int sum=0;
    int len=s.length();
    for(int i=0;i<s.length();i++) a[i]=s[i]-'0';
    // sort(a,a+len,less<int>());
    while(sum!=k){
        for(int i=0;i<len;i++){
            if(a[i]>a[i+1]) {
                a[i]=0;
                for(int k=i;k<len;k++) swap(a[k],a[k+1]);
                break;
                }
        }
        sum++;
    }
    int now=0;
    // for(int i=now;i<len;i++) cout<<a[i];
    // cout<<endl;
    while(!a[now]&&now<len) now++;
    // cout<<now<<endl;
    if(now==len) cout<<0;
    else for(int i=now;i<len-k;i++)if(a[i]!=-1) cout<<a[i];
    return 0;
}
