#include "iostream"
#include "string"
using namespace std;

int ans=0;
string word[100];
string start;
int visited[100],n;

bool check(string s1,string s2,int k){

    int lena=s1.length();
    for(int i=0;i<k;i++){
        if(s1[lena-k+i]!=s2[i]) return false;
    }
    return true;
}

void add(string a,string b ,int k){

    for(int i=k;i<b.length();i++){
        a+=b[i];
    }
}

void dfs(string p){
    int x=p.length();
    ans=max(x,ans);
    for(int i=0;i<n;i++){
        if(visited[i]>=2) continue;
        for(int k=1;k<=word[i].length();k++){
            if(check(p,word[i],k)){
                string temp=p;
                add(temp,word[i],k);
                if(temp.length()==p.length()) continue;
                visited[i]++;
                dfs(temp);
                visited[i]--;
            }
        }

    }

}





int main(int argc, char const *argv[])
{
    cin>>n;
    for(int i=0;i<n;i++) cin>>word[i];
    cin>>start;
    dfs(start);
    cout<<ans;
    return 0;
}
