#include "iostream"
#include "bits/stdc++.h"
#include "algorithm"
//macro
#define MAX 0x7fff
//using namespace
using namespace std;
//图为顶点0->n-1,matrix[i][j]表示i->j的距离
void dijkstra(int matrix[][9],int n,int begin){
    // int prev=begin;
    int distance[100],visit[100]={0};
    int p=0;
    for(int i=0;i<n;i++){
        distance[i]=matrix[begin][i];
    }
    p=begin;
    visit[p]=1;
    for (int i = 1; i < n; i++){
        for (int j = 0; j<n; j++)
        {
            int cost=distance[p]+matrix[p][j];
            if (visit[j]==0&&cost<distance[j]){
                distance[j]=cost;
                // visit[j]=1;
            }
        }
        for(int i=0;i<n;i++) cout<<' '<<distance[i]<<' ';
        cout<<endl;
        int min=MAX;
        for (int j = 0; j < n; j++){
            if(distance[j]<min&&visit[j]==0){
                min=distance[j];
                cout<<min<<' ';
                p=j;
            }
        }
        char c=p+'a';
        cout<<"chose "<<c<<endl;
        visit[p]=1;
    }
    for(int i=0;i<n;i++) cout<<i<<" 's distance is"<<distance[i]<<' '<<endl;

}


int main(int argc, char const *argv[])
{
    //a,b,c,d,e,f,g,h,I
    //0,1,2,3,4,5,6,7,9
    int matrix[9][9]={
        {0  ,9  , 2 , 6 ,MAX,MAX,MAX,MAX,MAX}, //a
        {MAX,0  ,MAX,MAX, 4 ,MAX,MAX,MAX,MAX},//b
        {MAX,MAX, 0 , 3 ,MAX, 1 ,MAX,MAX,MAX},//c
        {MAX, 2 ,MAX, 0 , 7 ,MAX, 9 ,MAX,MAX},//d
        {MAX,MAX,MAX,MAX,0,MAX,1,5,MAX},//e
        {MAX,MAX,MAX, 1 ,MAX, 0 ,MAX,MAX, 6 },//f
        {MAX,MAX,MAX, 1 ,MAX,MAX, 0 , 1 , 5 },//g
        {MAX,MAX,MAX,MAX,MAX,MAX,MAX, 0 ,MAX},//h
        {MAX,MAX,MAX,MAX,MAX,MAX,MAX, 5 , 0 }//i
    };
    dijkstra(matrix,9,0);
    return 0;
}
