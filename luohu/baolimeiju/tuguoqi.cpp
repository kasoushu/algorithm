#include"iostream"
#include "stdio.h"

using namespace std;
int w[51]={0},r[51]={0},b[51]={0},n,m,h=0x7fffffff;
string s;
int check(char c){
    int sum=0;
    for(int i=0;i<m;i++){
        if(s[i]!=c) sum++;
    }
    return sum;
}
int main(int argc, char const *argv[])
{
    cin>>n>>m;
    for (int i = 1; i <=n; i++){  
            cin>>s;
            w[i]=w[i-1]+check('W');
            r[i]=r[i-1]+check('R');
            b[i]=b[i-1]+check('B');
    }

    for (int i = 1; i <=n; i++)
    {
        for (int j = i+1; j <=n-1; j++){
            h=min(h,w[i]+b[j]-b[i]+r[n]-r[j]);
        }
        
    }
    cout<<h;
    
    return 0;
}
