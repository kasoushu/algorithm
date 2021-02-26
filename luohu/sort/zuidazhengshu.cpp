#include "iostream"
#include "algorithm"
#include "functional"

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    string s[21];
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        string ai;
        cin>>ai;
        s[i]=ai;
    }
    for (int i = 0; i <n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (s[j]+s[i]>s[i]+s[j]) swap(s[i],s[j]);
        }
    }
    for(int i=0;i<n;i++) cout<<s[i]<<' ';
    return 0;
}
