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
#define PII pair<int,int> 
using namespace std;

const int mm = 20;
char a[mm];

int main(int argc, char *argv[])
{
    int tot=0;
    for(int i =1 ;i<=13;i++){
        char c;
        cin>>c;
        if((c>='0'&&c<='9')){
            a[++tot] = c-'0';
        }else if(c=='X'){
            a[++tot] = 10;
        }
    }
    int sum = 0;
    for(int i =1;i<=9;i++){
        sum+=a[i]*i;
    }
    
    sum = sum%11;
    if(a[10]==sum){
        cout<<"Right"<<endl;
    }else{
        a[10] = sum;
        for(int i =1 ;i<=10;i++){
            // cout<<(a[i]==10?'X':a[i]);
            cout<<a[i];
            if(i==1) cout<<'-';
            if(i==4) cout<<'-';
            if(i==9) cout<<'-';
        }
    }

    return 0;
}
