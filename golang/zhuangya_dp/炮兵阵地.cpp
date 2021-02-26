
#include "bits/stdc++.h"
using namespace std;

int n,m,pic[155],inf;
long long F[3][1<<10][1<<10],ans=0;
char zifu[155];
int m_p[1<<12],num[1<<12],cnt;//m储存每一行的情况，num 储存该情况下的数量，值为情况


bool check(int k){
    
    // if( (k&(k<<1))!=0||(k&(k>>1))!=0 ) return false;
    // if( (k&(k<<2))!=0||(k&(k>>2))!=0 ) return false;
    // return true;
    int a=(k<<1),b=(k>>1);
    if((a&k)!=0||(b&k)!=0)return 0;
    a=(k<<2),b=(k>>2);
    if((a&k)!=0||(b&k)!=0)return 0;
    return 1;
}

bool check_map(int i,int a){ //a为情况,i为地形
    if((i&a)!=a) return 0;
    return 1;
}

int get_number(int a){ //计算改情况下能有几个跑兵
    int num=0;
    while(a)
    {
        if(a&1==1)num++;
        a>>=1;
    }
    return num;
}

bool check_paobing(int a,int b){ //检查a,b情况下炮兵是否相邻
    if((a&b)!=0) return false;
    return true;
}





int main(int argc, char const *argv[])
{
    cin>>n>>m;
    inf=(1<<m)-1;
    n+=1;
    

    
    for(int i=2;i<=n;i++){
        scanf("%s",zifu);
        for(int k=1;k<=m;k++){
            if(zifu[k-1]=='P') pic[i]=(pic[i]<<1)+1;
            else pic[i]=(pic[i]<<1);    }
        // cout<<pic[i]<<endl;
    }
    pic[0]=inf,pic[1]=inf;
    for(int i=0;i<=inf;i++){
        if(check(i)==1){
            cnt++;
            m_p[cnt]=i;
            num[cnt]=get_number(i);
        }
    }

    for(int i=2;i<=n;i++){
        for(int k=1;k<=cnt;k++){
            if(check_map(pic[i],m_p[k])==0) continue;
            for(int y=1;y<=cnt;y++){
                if(check_paobing(m_p[y],m_p[k])==0) continue;
                if(check_map(pic[i-1],m_p[y])==0) continue;
                for (int z = 1; z <=cnt; z++)
                {
                    if(check_map(pic[i-2],m_p[z])==0) continue;
                    if(check_paobing(m_p[z],m_p[y])==0||check_paobing(m_p[z],m_p[k])==0) continue;
                    // if(check_paobing(m_p[z],m_p[k])==0) continue;
                    F[i%3][m_p[k]][m_p[y]]=max(F[i%3][m_p[k]][m_p[y]],F[(i-1)%3][m_p[y]][m_p[z]]+num[k]);
                }
                // cout<<i-1<<" "<<m_p[k]<<" "<<m_p[y]<<" "<<F[i%3][m_p[k]][m_p[y]]<<endl;
            }
        }
    }
    for(int k=1;k<=cnt;k++){
        for(int y=1;y<=cnt;y++)
            ans=max(ans,F[n%3][m_p[k]][m_p[y]]);
    }
    cout<<ans;
    return 0;
}
