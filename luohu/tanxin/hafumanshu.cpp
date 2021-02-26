// hafumanshu.cpp
#include "stdio.h"
#include "iostream"
#include "vector"
using namespace std;
//http://c.biancheng.net/view/3398.html

typedef struct {
    int weight;
    int flag;
    int fa;
    int lc;
    int rc;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
}haffnode;

void buildhafftree(int n,int weight[]){
    vector<haffnode> haff(2*n-1);
    for (int i = 0; i < n; i++)
    {
        haffnode h;
        h.fa=-1;
        h.flag=0;
        h.lc=-1;
        h.rc=-1;
        haff.push_back(h);
    }


    for (int i = 0; i < n-1; i++){
        int x1=0x7fff,x2=0x7fff;
        int m1,m2;
        for (int j = 0; j < n+i; j++){
            
            if (haff[j].weight<x1&&haff[j].flag==0){
                m1=j;
                x1=haff[j].weight;
            }else if (haff[j].weight<x2&&haff[j].flag==0)
            {
                m2=j;
                x2=haff[j].weight;
            }
        }
        haff[m1].flag=1;
        haff[m2].flag=1;
        haff[m1].fa=n+i;
        haff[m2].fa=n+i;
        haff[n+i].lc=m1;        
        haff[n+i].rc=m2;        
        haff[n+i].weight=x2+x1;
    }
    
    
}

int main(int argc, char const *argv[])
{


	return 0;
}