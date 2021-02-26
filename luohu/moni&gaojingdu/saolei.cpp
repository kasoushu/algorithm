#include<stdio.h>
#include<iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    char map[102][102]={0};
    int n,m;
    char c;
    cin>>n>>m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <=m; j++)
        {
            cin>>c;
            if (c=='*')
            {
                map[i][j]=c;
            }else
            {
                map[i][j]='0';
            }        
        }
        
    }
    //计算周围雷数
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <=m; j++){
            if(map[i][j]=='*') continue;
            int count=0;
            //八个方向 i,j+1;i,j-1;i+1,j;i-1,j;i-1,j-1;i-1,j+1;i+1,j-1;i+1;j+1;
            if (map[i][j+1]=='*')count++;
            if (map[i][j-1]=='*')count++;
            if (map[i-1][j+1]=='*')count++;
            if (map[i-1][j-1]=='*')count++;
            if (map[i+1][j+1]=='*')count++;
            if (map[i+1][j-1]=='*')count++;
            if (map[i-1][j]=='*')count++;
            if (map[i+1][j]=='*')count++;
            map[i][j]='0'+count;
        }
    }
    //shuchu
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <=m; j++)
            printf("%c",map[i][j]);
        printf("\n");
    }


    return 0;
}