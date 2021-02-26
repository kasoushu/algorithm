#include <iostream>

using namespace std;
int main(int argc, char *argv[])
{
    int a;
    while(cin>>a){
        int sum =0;
        for(int i=1;i<=a;i++){
            sum+=i;
        }

        cout<<sum<<endl<<endl;
    }
    return 0;
}
