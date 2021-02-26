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

int pi[1000005]={0};
char s1[1000005],s2[1000005];
int main(int argc, char *argv[])
{
    // string s1,s2;
    // cin>>s1>>s2;
    cin>>s1+1;
    cin>>s2+1;
    int l1=strlen(s1+1);
    int l2=strlen(s2+1);
    // int l1=s1.size();
    // int l2=s2.size();
    for(int i=2;i<=l2;i++){
        int j=pi[i-1];
        while(j&&s2[j]!=s2[i]) j=pi[j-1];
        if(s2[i]==s2[j+1]) j++;
        pi[i]=j;
    }
    int j=0;
    for(int i=0;i<l1;i++){
        while(j&&s2[j+1]!=s1[i]) j=pi[j];
        if(s2[j+1]==s1[i]) j++;
        if(j==l2){
            cout<<i-j+2<<endl;
            j=pi[j];
        }
    }
    for(int i=1;i<=l2;i++){
        printf("%d ",pi[i]);
    }
    return 0;
}
