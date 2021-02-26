#include "iostream"
#include "stdio.h"
#include "algorithm"
using namespace std;

struct stu
{
    int num;
    int sroce;
    int math;
    int eng;
    int chinese;
}s[301];

bool cmp(stu a,stu b){
    if(a.sroce>b.sroce) return 1;
    else if(a.sroce<b.sroce) return 0;
    else
    {
        if (a.chinese>b.chinese) return 1;
        else if(a.chinese<b.chinese) return 0;
        else{
            if(a.num<b.num) return 1;
            else return 0;
        }
    }
    
}
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int k,m,e;
        cin>>k>>m>>e;
        s[i].chinese=k,s[i].math=m,s[i].eng=e,s[i].num=i+1,s[i].sroce=k+m+e;
    }
    sort(s,s+n,cmp);
    for(int i=0;i<5;i++){
        cout<<s[i].num<<' '<<s[i].sroce<<endl;
    }
    return 0;
}
