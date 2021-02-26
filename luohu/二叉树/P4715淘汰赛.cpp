#include "bits/stdc++.h"
using namespace std;

int n;
struct node{
    int score;
    int in;
}a[1024];
bool cmp(node q,node w){
    return q.score>w.score;
}
int main(int argc, char const *argv[])
{
    cin>>n;
    int x,i=0;
    int len=1<<n;
    int max1=0,max2=0,in1,in2;
    for(int i=1;i<=len;i++) {scanf("%d",&a[i].score);a[i].in=i;}
    sort(a+1,a+1+len/2,cmp);
    sort(a+2+len/2,a+len+1,cmp);
    cout<<(a[1].score<a[2+len/2].score?a[1].in:a[2+len/2].in)<<endl;
    return 0;
}
