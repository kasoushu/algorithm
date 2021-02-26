#include "iostream"
#include "string"
using namespace std;

string ans="";
string s;
string getans(){
   int n=0;
   char c;
   string s="";
   while(cin>>c){
   		if(c=='['){
   			cin>>n;
            string p=getans();
            for(int i=0;i<n;i++){
                s=s+p;
            }
   		}else
           {
               if(c==']') return s;
                else s=s+c;
           }
   }
   return s;
}

int main(int argc, char const *argv[])
{
    // string str;
    cout<<getans();
    // cout<<getans(0)<<endl;
    return 0;
}
