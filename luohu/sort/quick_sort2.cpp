#include "stdio.h"
#include "iostream"

using namespace std;
int k;
//left,right is index
void quick_sort(int a[],int left,int right){
    // cout<<left<<' '<<right<<endl;
    int x=left,y=right,t=a[(left+right)/2];
    if(left<right){
        do{
            while(a[x]<t) x++;
            while(a[y]>t) y--;
            if(x<=y){
                swap(a[x],a[y]);x++,y--;
            }
        }while(x<y);
        // for(int i=0;i<5;i++) cout<<a[i]<<' ';
        if(x<right) quick_sort(a,x,right);
        if(y>left) quick_sort(a,left,y);
    }

}

int main(int argc, char const *argv[])
{
    int n,a[5000000];
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>a[i];
    quick_sort(a,0,n-1);
    // for(int i=0;i<n;i++) cout<<a[i]<<' ';
    cout<<a[k]<<endl;
    return 0;
}
