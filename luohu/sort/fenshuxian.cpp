#include "iostream"
#include "stdio.h"
#include "algorithm"
using namespace std;
struct stu
{
    int num;
    int score;
}s[6000];

bool cmp(stu a,stu b){
    if(a.score>b.score) return 1;
    else if(a.score<b.score) return 0;
    else
    {
        if(a.num<b.num) return 1;
        else return 0;
    }
    
}

int main(int argc, char const *argv[]){
    int n,m,k;
    cin>>n>>m;
    k=m*1.5;
    for(int i=0;i<n;i++){
        int sc,num;
        cin>>num>>sc;
        s[i].score=sc,s[i].num=num;
    }
    sort(s,s+n,cmp);
    int a=s[k-1].score;
    for(int i=k;i<n;i++){
        if (s[i].score>=a){
            k++;
        }else break;
    }
    cout<<s[k-1].score<<' '<<k<<endl;
    for(int i=0;i<k;i++) cout<<s[i].num<<' '<<s[i].score<<endl;
    return 0;
}
