#include "stdio.h"
#include "iostream"
#define ll long long

using namespace std;
ll value[30][30][30]={0};

ll dfs(ll a,ll b,ll c){
    // cout<<a<<b<<c<<endl;
    if(a<=0||b<=0||c<=0) return value[0][0][0];
    else if(a>20||b>20||c>20) return value[20][20][20]=dfs(20,20,20);
    else if(a<b&&b<c){
        if(value[a][b][c]) return value[a][b][c];
        return value[a][b][c]=dfs(a,b,c-1)+dfs(a,b-1,c-1)-dfs(a,b-1,c);
    }    
    else {
        if(value[a][b][c]) return value[a][b][c];
        // value[a][b][c]=value[a-1][b][c]+value[a-1][b-1][c]+value[a-1][b][c-1]-value[a-1][b-1][c-1];
        return value[a][b][c]=dfs(a-1,b,c)+dfs(a-1,b-1,c)+dfs(a-1,b,c-1)-dfs(a-1,b-1,c-1); 
        }
}

int main(int argc, char const *argv[])
{
    value[0][0][0]=1;
    ll x,y,z;
    cin>>x>>y>>z;
    while(x!=-1||y!=-1||z!=-1){
        // printf("w(%ll,%ll,%ll) = %ll\n",x,y,z,dfs(x,y,z));
        cout<<"w("<<x<<", "<<y<<", "<<z<<")"<<' '<<'='<<' '<<dfs(x,y,z)<<endl;
        cin>>x>>y>>z;
    }
    // cout<<dfs(10,4,6)<<endl;
    // cout<<dfs(50,50,50)<<endl;
    // cout<<dfs(-1,7,18)<<endl;
    // cout<<dfs(17,17,18)<<endl;
    // cout<<dfs(19,17,18)<<endl;
    // cout<<dfs(21,-21,20)<<endl;
    // cout<<dfs(-1,-1,-11)<<endl;
    // cout<<dfs(21,-21,20)<<endl;
    return 0;
}
