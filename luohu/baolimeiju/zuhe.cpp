#include "iostream"
#include "stdio.h"

using namespace std;
int n,m,check[1000]={0},v[1000]={0};


void dfs(int k){
    if (k==m){
        for(int i=0;i<m;i++) printf("%3d",v[i]);
        cout<<endl;
        return;
    }
    for (int i =k>0?v[k-1]+1:1; i <= n; i++){
        if (!check[i]){
            v[k]=i;
            check[i]=1;
            dfs(k+1);
            check[i]=0;
        }
    }
    return;
}

int main(int argc, char const *argv[])
{
    cin>>n>>m;
    dfs(0);
    return 0;
}

// using namespace std;
// int n,m;//n为数的个数，m为位置的个数 
// int a[22],b[22];//a数组标记位置是否被占，b数组储存对应数值 
// void print(){
// 	for(int i = 1;i <= m;i++)
// 		printf("%3d",b[i]);//域宽为3，输出数值 
// 	printf("\n");//换行别忘了 
// }
// void dfs(int i){//搜索与回溯 
// 	if(i > m){
// 		print();//打印出结果 
// 		return;
// 	}
// 	for(int j = b[i - 1] + 1;j <= n;j++){
// 		if(!a[j]){
// 			a[j] = 1;
// 			b[i] = j;
// 			dfs(i + 1);//下一层递归 
// 			a[j] = 0;
// 		}
// 	}
// 	return;//回溯 
// }
// int main(){
// 	scanf("%d%d",&n,&m);
// 	dfs(1);//从1开搜 
// 	return 0;
// }