#include <iostream>
#include <algorithm>//快学学lower_bound()和upper_bound()吧
using namespace std;
const int MAXN = 1e6+5;
//都什么年代了还在用传统二分
int n,a[MAXN];
int bfind(int q)    //二分下标1~n
{
	int l = 0,r = n + 1;
	while (l+1<r) { //l+1==r结束
		int mid = (l + r) >> 1;
		if (a[mid] <= q) l = mid;
		else r = mid;
	}
	return l;
}
double qdfind(double y) //求一个浮点数的三次方根
{
	double l = -100,r = 100;
	while (r-1 > 1e-5) {
		double mid = (l+r)/2;
		if (mid*mid*mid <= y) l = mid;
		else r = mid;
	}
	return l;
}
int main ()
{
	return 0;
}