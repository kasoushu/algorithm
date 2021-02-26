#include "string"
#include "iostream"
#include "vector"
using namespace std;


//前缀函数；版本1 O(n^3)
vector<int> prefix_1(string s){
    int len=s.size();
    vector<int> pi(len,0);
    for(int i=1;i<len;i++){
        for(int j=i;j>=0;j--){
            if(s.substr(0,j)==s.substr(i-j+1,j)){
                pi[i]=j;
                break;
            }
        }
    }
    return pi;
}
//版本2 O(n^2)
vector<int> prefix_2(string s){
    int len=s.size();
    vector<int> pi(len,0);
    for(int i=1;i<len;i++){
        for(int j=pi[i-1]+1;j>=0;j--){
            if(s.substr(0,j)==s.substr(i-j+1,j)){
                pi[i]=j;
                break;
            }
        }
    }
    return pi;
}
//版本3 O(n)
vector<int> prefix_3(string s){
    int len=s.size();
    vector<int> pi(len,0);
    for(int i=1;i<len;i++){
        int j=pi[i-1];
        while(j>0&&s[i]!=s[j]) j=pi[j-1];
        if(s[j]==s[i]) j++;
        pi[i]=j;
    }
    return pi;
}

//KMP
// 查询t在s中的位置
int kmp(string s,string t){
    int m=s.size();
    int n=t.size();
    string k=t+"#"+s;
    int len=k.size();
    vector<int> pi(len,0);
    for(int i=1;i<len;i++){
        int j=pi[i-1];
        while(j>0&&k[j]!=k[i]) j=pi[j-1];
        if(k[j]==k[i]) j++;
        pi[i]=j;
        if(pi[i]==n){
            return i-2*n;
            break;
        }
    }
    return -1;

}

void pri(vector<int> p){
    for(int i=0;i<p.size();i++){
        cout<<p[i]<<' ';
    }
    cout<<endl;
}


int main(int argc, char const *argv[])
{
    string ss="abcabcd";
    pri(prefix_1(ss));
    pri(prefix_2(ss));
    pri(prefix_3(ss));
    cout<<kmp("hello","ll");
    return 0;
}
