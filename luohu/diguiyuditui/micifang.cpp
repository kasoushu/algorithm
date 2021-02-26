#include "stdio.h"
#include "iostream"

using namespace std;
// string fff(int i){
//     string s="";
//     if(i==0) return "";
//     if(i==1) return "2(0)";
//     if(i==2) return "2";
//     while(i){
//         i/=2;
//         if(i&1){
//             s=fff(i)+s;
//         }
//         // s=s+")";
//     }
//     return s;
// }


string acccc(int p){
    string s="";
    if(p==0) return "0";
    int k=0;
    while(p){
        if (p&1){
            s=(k==1?"2":"2("+acccc(k)+")")+(s==""?"":"+")+s;
        }
        p>>=1;
        k++;
    }
    return s;
}


int main(int argc, char const *argv[])
{
    int n=0;
    cin>>n;
    cout<<acccc(n);
    return 0;
}
