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

const int mm = 6*6+5;

int hang[mm][mm],lie[mm][mm],blok[mm][mm];
int nn,n,t;


int main(int argc, char *argv[])
{
    cin>>t;
    for(int k =1;k<=t;k++){
        cin>>nn;
        n=nn*nn;
        bool flag = 1;
        memset(hang,0,sizeof(hang));
        memset(lie,0,sizeof(lie));
        memset(blok,0,sizeof(blok));
        for(int i =1 ;i <= n ;i++){
            for(int j = 1;j<=n;j++){
                int x;
                scanf("%d",&x);
                if(x<=n&&x>=1){
                    hang[i][x]++;
                    lie[j][x]++;
                    blok[((i-1)/nn)*nn+(j-1)/nn+1][x]++;
                }else{
                    flag = 0;
                }
            }
        }
        if(flag){
            for(int i =1 ;i<=n;i++){
                for(int j =1 ;j<=n;j++){
                    if(hang[i][j]>1||hang[i][j]<=0){
                        flag = 0;
                        break;
                    }
                    if(lie[i][j]>1||lie[i][j]<=0){
                        flag = 0;
                        break;
                    }
                    if(blok[i][j]>1||blok[i][j]<=0){
                        flag = 0;
                        break;
                    }
                }
                if(!flag) break;
            }
        }
        if(flag){
            printf("Case #%d: Yes\n",k);
        }else{
            printf("Case #%d: No\n",k);
        }

    }
    return 0;
}

作者：jjck
链接：https://www.acwing.com/activity/content/code/content/790102/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
