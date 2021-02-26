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
const int MN = 22;

int a[mm],w[mm],xo[mm],ch[mm][2];
int n ,tot=0,rec[mm],rek[mm],ans = 0,l,r;
int mknode(){
    tot++;
    xo[tot] = w[tot] = ch[tot][0] =ch[tot][1] = 0;
    // cout<<tot<<' ';
    return tot;
}

void maintain(int now){
    w[now] = xo[now] = 0;
    if(ch[now][0]){
        w[now] += w[ch[now][0]];
        xo[now] ^= xo[ch[now][0]]<<1;
    }
    if(ch[now][1]){
        w[now] += w[ch[now][1]];
        xo[now] ^=( xo[ch[now][1]]<<1 ) | (w[ch[now][1]]&1);
    }
    w[now] = w[now] & 1;
}

void insert(int now,int v,int dp,int i){
    if(!now) now = mknode();
    if(dp > MN){
        rek[now] = i;
        rec[i] = now;
        return (void)(w[now]++);
    }
    insert(ch[now][v&1], v>>1, dp+1,i);
    maintain(now);
}

void get_max(int v,int d){
    int p=rec[d],res = 0;
    for(int i = MN;i>=0;i--){
        int k = (v>>i)& (1);
        if(ch[p][k^1]){
            res += 1<<i;
            p = ch[p][k^1];
        }else{
            p = ch[p][k];
        }
    }
    cout<<"res : "<<res<<endl;
    if(res > ans){
        ans = res;
        l = rek[p];
        r = d;
    }
}
/*  */
int main(int argc, char *argv[])
{
    cin>>n;
    for(int i = 1 ; i<= n;i++){
        cin>>a[i];
        a[i]^=a[i-1];
    }
    for(int i =1;i<=n;i++){
        get_max(a[i], i);
        insert(0, a[i], 0, i);
        // cout<<tot<<' ';
    }
    cout<<ans<<' '<<l<<' '<<r<<endl;
    return 0;
}





