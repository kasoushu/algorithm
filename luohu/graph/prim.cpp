#include "iostream"
#include "stdlib.h"
#define N 7
#define E 11
#define MAX 0x7fffffff
using namespace std;
//假设我要得到最小生成树的路径和
int prim(int matrix[][N],int n,int begin){
    int visit[N]={0},r_length[N];
    int sum=0;
    int now=begin;
    visit[begin]=1;
    for (int i =0; i <n; i++){
        r_length[i]=matrix[now][i];
    }
    for(int x=1;x<n;x++) cout<<r_length[x]<<' ';
    cout<<endl;
    for (int i = 0; i < n-1; i++){
    
        int min=MAX;
        for (int k = 1; k < n; k++){
            if(visit[k]==0&&r_length[k]<min){
                min=r_length[k];
                now=k;
            }}
        if(min<MAX) sum+=min;
        // cout<<sum<<endl;
        visit[now]=1;
        for (int j = 1; j <n; j++)
        {
            if (visit[j]==0&&matrix[now][j]<r_length[j]){
                r_length[j]=matrix[now][j];
            }
        }
        for(int x=1;x<n;x++) cout<<r_length[x]<<' ';
        cout<<endl;
    }
    return sum;

}




int main(int argc, char const *argv[])
{

    int e[10][3]={
        {1,2,6},
        {1,4,5},
        {1,3,1},
        {2,3,5},
        {5,2,3},
        {5,6,6},
        {5,3,6},
        {3,6,4},
        {4,3,5},
        {4,6,2},
    };
    int a[N][N];
    for(int i=0;i<N;i++) for(int j=0;j<N;j++) a[i][j]=MAX;
    cout<<endl;
    for (int i = 0; i < E; i++)
    {
        if(i<N) a[i][i]=0;
        a[e[i][0]][e[i][1]]=e[i][2];
        a[e[i][1]][e[i][0]]=e[i][2];
    }
    // for(int i=1;i<2;i++) for(int j=0;j<11;j++) cout<<a[i][j]<<' ';
    cout<<prim(a,7,1);

    return 0;
}
