#include "stdio.h"
#include "iostream"
#include "string"

using namespace std;

int main(int argc, char const *argv[])
{
    string s1,s2,s;
    int n1,n2,cf=0,temp;
    cin>>s1>>s2;
    n1=s1.size();
    n2=s2.size();
    if(n2>n1) for ( int i = 0; i < n2-n1; i++) s1="0"+s1;
    else for (int i=0;i<n1-n2;i++) s2="0"+s2;
    for (int i = s1.size()-1; i >=0; i--)
    {
        temp=cf+s1[i]-'0'+s2[i]-'0';
        cf=temp/10;
        s=char(temp%10+'0')+s;
    }
    if (cf!=0)
    {
        s=char(cf+'0')+s;
    }
    
    cout<<s;
    return 0;
}