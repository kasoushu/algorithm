#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define ll long long
#define orz cout<<"LKP AK IOI";
const int maxn = 1e6 + 5;
using namespace std;
int n, nxt[maxn], k;
ll ans;
char s[maxn];
inline int read() {
    register int x = 0, y = 1;
    register char c = getchar();

    while (c < '0' || c > '9') {
        if (c == '-')
            c = getchar();
    }

    while (c >= '0' && c <= '9') {
        x = x * 10 + (c ^ 48);
        c = getchar();
    }

    return y ? x : -x;
}
int main() {
    n = read();
    scanf("%s", s + 1);
    nxt[0] = 0;
    nxt[1] = 0;
    nxt[2] = 0;

    for (int i = 1; i < n; i++) {
        while (k && s[i + 1] != s[k + 1])
            k = nxt[k]; //如果不匹配，就向前找net,直到没有

        if (s[i + 1] == s[k + 1])
            k++;//如果有，匹配数加1

        nxt[i + 1] = k;
    }
    for(int i=1;i<=n;i++) cout<<nxt[i]<<' ';
    for (int i = 1; i <= n; i++) {
        k = i;

        while (nxt[k] > 0)
            k = nxt[k];

        if (nxt[i] > 0)
            nxt[i] = k;
        ans += i - k; //求出最小距离
        for(int i=1;i<=n;i++) cout<<nxt[i]<<' ';
        cout<<endl;
    }

    printf("%lld", ans);
    return 0;
}
