#include "vector"
#include "bits/stdc++.h"
#include "map"
#include "queue"
#include "algorithm"
#include "stdio.h"
#include "iostream"
#define ll long long
#define INF 0x3f3f3f3f
#define low_bit(x) ((x)&(-x))
using namespace std;

int main(int argc, char *argv[])
{
    string s1,s2;
    cin>>s1;
    cin>>s2;
    int cnt=0; 
    int len=s1.size();
    for(int i=0;i+1<len;i++){
        if(s1[i]!=s2[i]){
            cnt++;
            if(s1[i]=='*') s1[i]='o'; else s1[i]='*';
            if(s1[i+1]=='*') s1[i+1]='o';else s1[i+1]='*';
        }
    }
    cout<<cnt<<endl;
    return 0;
}
