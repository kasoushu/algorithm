#include "vector"
#include "bits/stdc++.h"
#include "map"
#include "queue"
#include "algorithm"
#include "stdio.h"
#include "iostream"
#include <algorithm>
#define ll long long
#define INF 0x3f3f3f3f
#define low_bit(x) ((x)&(-x))
#define PII pair<int,int> 
using namespace std;

int a[100],b[100];

//add s2->s1
string add(string s1,string s2){
    int l1=s1.size();
    int l2=s2.size();
    string c="";
    if(l1<l2) return add(s2,s1);
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(), s2.end());
    int ov=0;
    int i=0;
    for(i=0;i<l2&&i<l1;i++){
        int ad=s1[i]-'0'+s2[i]-'0'+ov;
        ov=ad/10;
        ad=ad%10;
        c = c+(char)(ad+'0');
    }
    if(i<l1){
        for(;i<l1;i++){
            int ad=s1[i]-'0'+ov;
            ov=ad/10;
            ad=ad%10;
            c +=(char)(ad+'0');
        }
    }
    if(ov){
        c=c+(char)(ov+'0');
    }
    reverse(c.begin(), c.end());
    return c;
}

int main(int argc, char *argv[])
{
    string s1,s2;
    cin>>s1>>s2;
    // while(cin>>s1>>s2){
        cout<<add(s1,s2);
    // }
    return 0;
}

