// hafumanshu.cpp
#include "stdio.h"
#include "iostream"
#include "vector"
#include "queue"
using namespace std;
//haffman tree =>hebingguozi
// int a[10005]={0};
// int n;
// int haff_build(){
//     int m1=0x7fffffff,m2=0x7fffffff,n1=-1,n2=-1;
//     for (int i = 0; i < n; i++)
//     {
//         if (a[i]!=0&&a[i]<m1){
//             n2=n1,n1=i;
//             m2=m1,m1=a[i]; 
//             // cout<<"m1="<<m1<<' ';
//         }else if(a[i]!=0&&a[i]<m2){
//             n2=i;
//             m2=a[i];
//             // cout<<"m2="<<m2<<' ';
//         }
//         // cout<<m1+m2;
//     }
//     a[n1]=0;
//     a[n2]=m1+m2;
//     // cout<<endl;
//     return m1+m2;
// }


// int main(int argc, char const *argv[])
// {
//     cin>>n;
//     int sum=0;
//     for(int i=0;i<n;i++) cin>>a[i];
//     for(int i=0;i<n-1;i++) sum+=haff_build(); 
//     cout<<sum;
//     return 0;
// }



//priority_queue => hebingguozi
int main(int argc, char const *argv[])
{
    int n,sum=0;
    priority_queue<int ,vector<int>,greater<int> > q;
    cin>>n;
    for(int i=0;i<n;i++) {int x;cin>>x;q.push(x);}
    while (q.size()>=2){
        int x=0,y=0;
        x=q.top(),q.pop();
        y=q.top(),q.pop();
        sum+=x+y;
        q.push(x+y);
    }
    cout<<sum;
    return 0;
}
