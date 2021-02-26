#include "stdio.h"
#include "iostream"

using  namespace std;

int main(){
    int a,b,k,d,e,f,g,h,i,j,n,count=0;
    int v[5000][11];
    cin>>n;
    for(int a=1;a<=3;a++)
    for(int b=1;b<=3;b++)
    for(int k=1;k<=3;k++)
    for(int d=1;d<=3;d++)
    for(int e=1;e<=3;e++)
    for(int f=1;f<=3;f++)
    for(int g=1;g<=3;g++)
    for(int h=1;h<=3;h++)
    for(int i=1;i<=3;i++)
    for(int j=1;j<=3;j++){
        if (a+b+k+d+e+f+g+h+i+j==n){
            v[count][0]=a;
            v[count][1]=b;
            v[count][2]=k;
            v[count][3]=d;
            v[count][4]=e;
            v[count][5]=f;
            v[count][6]=g;
            v[count][7]=h;
            v[count][8]=i;
            v[count][9]=j;
            count++;
        }
    }
    cout<<count<<endl;
    for(int i=0;i<count;i++) {
        for (int j = 0; j < 10; j++)
            cout<<v[i][j]<<' ';
        cout<<endl;
    }
    }
