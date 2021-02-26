#include "iostream"
#include "algorithm"

using namespace std;
typedef struct guowangyouxi
{
    int a;
    int b;
}number;


int n,a0,b0;
number a[1000];
//
void cheng(int a[],int b[]){
    int len1=a[0],len2=b[0];
    int c[1000]={0};
    int clen=len1+len2;
    // c=(int *)malloc(sizeof(int)*clen);
    // c= new int[clen+1]();
    // for(int i=0;i<clen;i++)  cout<<c[i]<<' ';
    for(int i=1;i<=clen;i++){
        for(int j=1;j<=i;j++){
            c[i]+=a[j]*b[i+1-j];
            if (c[i]>=10)
            {
                c[i+1]++;
                c[i]%=10;
            }
        }
    }
    while(!c[clen]) clen--;
    c[0]=clen;
    for(int i=0;i<1000;i++) a[i]=c[i];
    // return c;
}
//gaojing / dijing chufa; jieguo cao cun zai a;
void chufa(int a[],int b){
    int x=0,lena;
    int c[1000]={0};
    lena=a[0];
    for(int i=lena;i>0;i--){
        c[i]=(x*10+a[i])/b;
        x=(x*10+a[i])%b;
    }
    while(!c[lena]) lena--;
    c[0]=lena;
    for(int i=0;i<=lena;i++) a[i]=c[i];

}



bool cmp(number a,number b){
    return a.a*a.b<b.a*b.b?1:0;
}
int main(int argc, char const *argv[])
{
    cin>>n;
    cin>>a0>>b0;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        a[i].a=x,a[i].b=y;
    }
    sort(a,a+n,cmp);
    int m[1000]={0};
    for(int i=0;i<n;i++){
        int k[1000]={1,1,0};
        for(int j=0;j<i;j++){
            int nownum=a[j].a;
            cout<<"nownum="<<a[j].a;
            int lena=0,p[1000]={0};
            for(int l=1;nownum>0;l++){p[l]=nownum%10;nownum/=10;lena++;}
            p[0]=lena;
            for(int i=m[0];i>=0;i--) cout<<m[i];
            cout<<endl;
            cheng(k,p);
        }
        chufa(k,a[i].b);
        for(int jck=1;jck<=k[0];jck++) if(k[jck]>m[jck]){for(int ll=0;ll<=k[0];ll++) m[ll]==k[ll];}
    }
    for(int i=m[0];i>=0;i--) cout<<m[i];
    return 0;
}


// int main(int argc, char const *argv[])
// {
//     int x[1000]={3,3,2,1};
//     int y[1000]={3,0,2,1};
//     cheng(x,y);
//     for(int i=x[0];i>0;i--) cout<<x[i]<<' ';
//     cout<<endl;
//     chufa(x,3);
//     for(int i=x[0];i>0;i--) cout<<x[i]<<' ';
//     return 0;
// }
