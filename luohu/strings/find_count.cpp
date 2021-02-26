P#include "string"
#include "iostream"

int main(){
    std::string a,b;
    getline(std::cin,a);
    getline(std::cin,b);

    for (int i = 0; i < a.length(); ++i) {
        a[i]=std::tolower(a[i]);
    }
    for (int i = 0; i < b.length(); ++i) {
        b[i]=std::tolower(b[i]);
    }
//    int n,count=0;
    a=' '+a+' ';
    b=' '+b+' ';
    if (b.find(a)==std::string::npos) std::cout<<-1;
    else{
        int alpha=b.find(a),s=0;
        for (int beta =b.find(a); beta!=std::string::npos;beta=b.find(a,beta+1)) {
            s++;
        }
        std::cout<<s<<" "<<alpha<<std::endl;//输出第一个和总共有几个
    }
    return 0;
}