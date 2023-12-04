#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define int long long
const int MAXN = 110000002;
int n,dp[MAXN];			//回文半径
char str[MAXN<<1],a[MAXN];
void change ()
{
	n = strlen(a);
	int k = 0;
	str[k++] = '$';
	str[k++] = '#';
	for (int i = 0 ; i < n ; i++ ) {
		str[k++] = a[i];
		str[k++] = '#';
	}
	str[k++] = '&';
	n = k;
}
void getDP()
{
	for (int i = 1 , c ,r = 0 ; i < n ; ++i ) {
		if (i < r) {
			dp[i] = min(dp[(c<<1) - i] , dp[c] + c - i);
		} else {
			dp[i] = 1;
		}
		while (str[i - dp[i]] == str[i + dp[i]]) {
			dp[i]++;
		}
		if (i + dp[i] > r) {
			c = i;
			r = i + dp[i];
		}
	}
}

signed main ()
{
	scanf("%s",a);
	change();
	getDP();
	int ans = 1;
	for (int i = 0 ; i < n ; i++ ) {
		ans = max(ans,dp[i]);
	}
	printf("%lld\n",ans-1);
	return 0;
}