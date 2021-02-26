#include "iostream"
using namespace std;
int a[1000];
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

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
