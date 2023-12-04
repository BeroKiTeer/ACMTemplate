#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 2023;
int dp[MAXN][MAXN];
int main ()
{
	string a,b;
	cin >> a >> b;
	int as = a.size(),bs = b.size();
	for (int i = 1 ; i <= as ; i++ ) {
		dp[i][0] = i;
	}
	for (int i = 1 ; i <= bs ; i++ ) {
		dp[0][i] = i;
	}
	for (int i = 1 ; i <= as ; i++ ) {
		for (int j = 1 ; j <= bs ; j++ ) {
			if (a[i-1] == b[j-1]) {
				dp[i][j] = dp[i-1][j-1];
			} else {
				dp[i][j] = min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j])) + 1;
			}
		}
	}
	cout << dp[as][bs] << endl;
	return 0;
}