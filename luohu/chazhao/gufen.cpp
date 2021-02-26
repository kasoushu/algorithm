#include "iostream"
#include "algorithm"
using namespace std;
int n,m;
int school[100005],stu[100005];
int find_x(int x){
    int l=0,r=m-1;
    while (l<r){
        int mid=(l+r)/2;
        // cout<<"mid ="<<mid<<' '<<school[mid]<<' ';
        if(school[mid]>x) r=mid;
        else if(school[mid]<=x) l=mid+1;
    }
    return l==0?school[0]-x:min(abs(school[l]-x),abs(school[l-1]-x));
}

int main(int argc, char const *argv[])
{
    cin>>m>>n;
    for(int i=0;i<m;i++) cin>>school[i];
    for(int i=0;i<n;i++) cin>>stu[i];
    long long sum=0;
    sort(school,school+m);
    for(int i=0;i<n;i++){
        // cout<<find_x(stu[i])<<endl;
        sum+=abs(find_x(stu[i]));
    }
    // for(int i=0;i<m;i++) cout<<school[i]<<' ';
    // cout<<endl;
    // cout<<find_x(550);
    cout<<sum;
    return 0;
}
