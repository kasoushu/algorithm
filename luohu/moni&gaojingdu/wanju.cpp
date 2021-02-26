#include<stdio.h>
#include<iostream>
#include "string"
using namespace std;
//0, in,1 out,设顺时针为+逆时针为-，当 0 时 左为顺，右为逆，当1时 左为逆右为顺
//0,left,1,right
//flag[i] => out or in 
struct node
{
    int head;
    string s;
}a[100005];


int main(int argc, char const *argv[])
{
    int n,m,now=0;
    cin>>n>>m;
    for (int i =0; i <n; i++)
    {
        cin>>a[i].head>>a[i].s;
    }
    for (int i = 1; i <=m; i++)
    {
        int f,step;
        cin>>f>>step;
        if(a[now].head==0&&f==0) now=(now+n-step)%n;
        else if(a[now].head==0&&f==1) now=(now+n+step)%n;
        else if(a[now].head==1&&f==0) now=(now+n+step)%n;
        else if(a[now].head==1&&f==1) now=(now+n-step)%n;
    }
    cout<<a[now].s;
    return 0;
}
