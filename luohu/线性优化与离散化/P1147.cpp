#include <iostream> 
#include <algorithm> 
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <bits/stdc++.h>
using namespace std;
int m=0;
//会超时
int main(int argc, char const *argv[])
{
    cin>>m;
    queue<int> a;
    for (int  l= 1; l <m; l++)
    {
        /* code */
        for (int  r = l+1; r< m; r++)
        {
            int  sum=(l+r)*(r-l+1)/2;
            if(sum==m){
                printf("%d %d\n",l,r);
            }
        }
    }
    return 0;
}
/*****正解
/*****
****/

// #include<bits/stdc++.h>
// using namespace std;
// int m;
// int main(){
//     cin>>m;
//     for(int k1=sqrt(2*m);k1>1;k1--)//枚举k1(注意是k1>1而不是k1>=1)
//         if(2*m%k1==0 && (k1+2*m/k1)%2){//如果K2是整数而且与K1一奇一偶
//             int k2=2*m/k1;
//             cout<<(k2-k1+1)/2<<" "<<(k1+k2-1)/2<<endl;//输出答案
//         }
//     return 0;
// }