#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>//头文件不用说了，虽然还有一些没有用到，但是懒得删
using namespace std;
void cheng(long long a[],long long b[])//算高精度两数相乘，结果只留500位
{
    int c[100000]={0};
    c[0]=a[0]+b[0];
    if(c[0]>500) c[0]=500;
    for(int i=0;i<b[0];i++)
    {
        for(int q=0;q<a[0];q++)
        {
            c[i+q+1]=a[q+1]*b[i+1]+c[i+q+1];
            if(c[i+q+1]>=10)
            {
                c[i+q+2]=c[i+q+2]+c[i+q+1]/10;
                c[i+q+1]=c[i+q+1]%10;
            }
        }
    }
    for(int i=0;i<=c[0];i++) a[i]=c[i];
}
void sc(long long a[])//输出……拼音大法好啊……
{
    int q=500;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<50;j++)
        {
            cout<<a[q];
            q--;
        }
        cout<<endl;
    }
}
int main()
{
    long long a[5000]={0},b,c[50000]={0};//这里c是2的幂，a是结果，b输入的参数。
    a[0]=a[1]=c[0]=1;c[1]=2;//这里把2的幂先设成2，不然平方的时候永远是1……
    cin>>b;
    a[1]=2;
    int k=0.30103*b+1;//算位数，不要问我为什么这样算，上网搜去……
    cout<<k<<endl;
    if(b&1!=0) {cheng(a,a);b>>1;};
    // b=b>>1;
    cout<<a[1]<<endl;
    // cout<<b<<endl;
    while(b>1)
    {
        // if(b&1!=0) cheng(a,c);
        cheng(a,a);
        if(b&1!=0) cheng(a,c);
        // sc(c);
        b=b>>1;
}
    a[1]--;
    sc(a);
    cout<<endl;
    return 0;
}