#include <iostream>
#define int long long
using namespace std;
int fastPow(int a,int n,int mod)
{
    int ans = 1;
    a %= mod;
    while (n) {
        if (n & 1) {
            ans = (ans * a) % mod;
        }
        a = (a*a)%mod;
        n >>= 1;
    }
    return ans;
}
int fastPow(int a,int n)
{
    int ans = 1;
    while (n) {
        if (n&1) ans *= a;
        a *= a;
        n >>= 1;
    }
    return ans;
}
signed main ()
{
    return 0;
}