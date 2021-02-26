#include "iostream"


using namespace std;

void maopao_sort(int a[],int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j+1 < n-i; j++)
        {
            if (a[j]>a[j+1])
            {
                swap(a[j],a[j+1]);
            }
            
        }
        
    }
    

}

void p_a(int a[],int n){
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<' ';
    }
    cout<<endl;
}


int main(int argc, char const *argv[])
{
    int a[]={4,2,3,7,5,1};   
    maopao_sort(a,6);
    p_a(a,6); 
    return 0;
}
