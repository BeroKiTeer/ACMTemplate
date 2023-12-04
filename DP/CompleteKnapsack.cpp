#include <iostream>
using namespace std;
const int MAXN = 10005;
int dp[MAXN],a[MAXN],v[MAXN];
int main ()
{
	int t,m;
	cin >> t >> m;
	for (int i = 1 ; i <= m ; i++ ) {
		cin >> a[i] >> v[i];
	}
	for (int i = 1 ; i <= m ; i++ ) {
		for (int j = a[i] ; j <= t ; j++ ) {
			if (dp[j] <= dp[j-a[i]] + v[i]) {
				dp[j] = dp[j-a[i]] + v[i];
			}
		} 
	}
	cout << dp[t] << endl;
	return 0;
}