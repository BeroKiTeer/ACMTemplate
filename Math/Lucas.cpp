#include <iostream>
#define int long long
using namespace std;
const int MAXN = 100010;
int fac[MAXN];
void initFac(int mod)       //阶乘打个表先
{
    fac[0] = 1;
    for (int i = 1 ; i <= mod ; ++i ) {
        fac[i] = (fac[i-1]*i)%mod;
    }
}
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
int inverse (int a,int mod)     //费马小定理除法取模
{
	return fastPow(fac[a],mod-2, mod);
}
int C(int n,int r,int mod)
{
	if (r > n) {
		return 0;
	}
	return ((fac[n]*inverse(r,mod))%mod * (inverse(n - r, mod)) % mod);
}
int lucas (int n ,int r , int mod)
{
	if (r == 0) {
		return 1;
	}
	return C(n%mod,r%mod,mod) * lucas(n/mod, r/mod, mod);
}
signed main ()
{
	int t; cin >> t;
	while (t--) {
		int n,m,p;
		cin >> n >> m >> p;
		initFac(p);
		cout << lucas(n+m,n,p)%p << endl;
	}
	return 0;
}