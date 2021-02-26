#include "iostream"
#include "algorithm"
#include "vector"
#define N 7 //节点共6个，从1开始数的话N应该为7
#define E 10
using namespace std;
//集合
int a[1000]={0};
//并查集实现;设数组s[],下标i的值s[i]=f（f为父节点），祖先的父节点为他自身。
//find输入节点x ，返回祖先节点r,
//union,合并两个并查集，将a的祖先节点设置为b的子节点
int find_set(int x){
    int r=x;
    while(a[r]!=r) r=a[r];
    int y=x,t;
    while(a[y]!=r) {t=a[y];a[y]=r;y=t;}
    return r;
}
//union
void union_set(int x,int y){
    int i,j;
    i=find_set(x),j=find_set(y);
    if(i!=j) a[i]=j;
}

bool cmp(vector<int> a,vector<int> b){
    return a[2]<b[2]?1:0;
}

int krusal(int node[],vector<vector<int>> edges,int n,int e){
    int already_edge=0,sum=0;
    sort(edges.begin(),edges.end(),cmp);
    for (int i = 0; i <e; i++){
        int x,y;
        x=find_set(edges[i][0]);
        y=find_set(edges[i][1]);
        if (x!=y){
            union_set(x,y);
            sum+=edges[i][2];
            already_edge++;
        }
        
        if(already_edge==n-1) return sum;
    }
    
    return sum;

}



int main(int argc, char const *argv[])
{
    vector<vector<int>> e={
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
    for(int i=0;i<N;i++) a[i]=i;
    cout<<krusal(a,e,N,E);
    return 0;
}
