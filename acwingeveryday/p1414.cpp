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

const int mm = 100050;
const int MN =22;

int w[mm],ch[mm][2],ox[mm],dp[mm];
int n,ans=0,l,r,tot,a[mm];

void insert(int v,int w ){
    int p =0;
    for(int i = MN;i >=0 ; i-- ){
        int k = (v>>i) & 1;
        if(!ch[p][k])  ch[p][k] = ++tot;
        p = ch[p][k];
    }
    dp[p] = w;
}

void get_max(int val,int w){
    int p = 0,res = 0;
    for(int i = MN;i>=0;i--){
        int k = (val>>i) & 1;
        if(ch[p][k^1]){
            res  = res | (1<<i);
            p = ch[p][k^1];
        }else{
            p = ch[p][k];
        }
    }
    if(res > ans){
        ans = res ;
        l = dp[p] + 1;
        r= w;
    }
}

int main(int argc, char *argv[])
{
    cin>>n;
    for(int i =1; i<= n ;i++){
        cin>>a[i];
        a[i] = a[i]^a[i-1];
    }
    for(int i =1 ;i<=n;i++){
        get_max(a[i], i);
        insert(a[i], i);
    }
    
    cout<<ans<<' '<<l<<' '<<r;
    return 0;
}

//****************************************************************************************\\
//                                                                                        \\
//                                                    __----~~~~~~~~~~~------___          \\
//                                   .  .   ~~//====......          __--~ ~~              \\
//                   -.            \_|//     |||\  ~~~~~~::::... /~                       \\
//                ___-==_       _-~o~  \/    |||  \            _/~~-                      \\
//        __---~~~.==~||\=_    -_--~/_-~|-   |\   \        _/~                            \\
//    _-~~     .=~    |  \-_    '-~7  /-   /  ||    \      /                              \\
//  .~       .~       |   \ -_    /  /-   /   ||      \   /                               \\
// /  ____  /         |     \ ~-_/  /|- _/   .||       \ /                                \\
// |~~    ~~|--~~~~--_ \     ~==-/   | \~--===~~        .\                                \\
//          '         ~-|      /|    |-~\~~       __--~~                                  \\
//                      |-~~-_/ |    |   ~\_   _-~            /\                          \\
//                           /  \     \__   \/~                \__                        \\
//                       _--~ _/ | .-~~____--~-/                  ~~==.                   \\
//                      ((->/~   '.|||' -_|    ~~-/ ,              . _||                  \\
//                                 -_     ~\      ~~---l__i__i__i--~~_/                   \\
//                                 _-~-__   ~)  \--______________--~~                     \\
//                               //.-~~~-~_--~- |-------~~~~~~~~                          \\
//                                      //.-~~~--\                                        \\
//                  神兽保佑                                                              \\
//                代码无BUG!)                                                             \\
//****************************************************************************************\\

