#include "iostream"
#include "math.h"
#include "cstring"
#include "cstdio"
using namespace std;

double x[20],y[20];
double F[20][65536];
int n;
double a[20][20];
double ans=0x7fffffff;
double get_dis(int i,int j){
    return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}

double get_ans(){
    memset(F,127,sizeof(F));
    for(int i=0;i<=n;i++){
        for (int j = i+1; j <=n; j++)
        {
            a[i][j]=get_dis(i,j);
            a[j][i]=a[i][j];
        }
    }
    //F初始化 第一个点的距离
    for(int i=1;i<=n;i++){
        F[i][1<<(i-1)]=a[0][i];
    }
    //状态压缩
    for (int k = 3; k<(1<<n); k++)
    {
        for(int i=1;i<=n;i++){
            if(!(k&(1<<(i-1)))) continue;
            for(int j=1;j<=n;j++){
                if(i==j) continue;
                if(!(k&(1<<(j-1)))) continue;
                // cout<<"i="<<i<<' '<<"j="<<j<<"k="<<k<<endl;
                F[i][k]=min(F[i][k],F[j][k-(1<<(i-1))]+a[i][j]);
            }
        }
    }
    // if(n==11) return F[2][(1<<n)-1];
    // cout<<F[2][(1<<n)-1]<<endl;
    // for(int i=1;i<=n;i++) cout<<(F[i][(1<<n)-1])<<' ';
    // cout<<endl;
    for(int i=1;i<=n;i++) {ans=min(F[i][(1<<n)-1],ans);}
    return ans;

}

int main(int argc, char const *argv[])
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
    }
    x[0]=0;y[0]=0;
    printf("%.2f",get_ans());
    return 0;
}
