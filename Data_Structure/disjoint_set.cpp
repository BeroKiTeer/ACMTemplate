#include <iostream>
using namespace std;
const int MAXN = 1050;
int s[MAXN];
//初始化
void init_set()
{
	for (int i = 0 ; i < MAXN ; i++ ) s[i] = i;
}
//查找（非路径压缩）
int findset(int x)
{
	return x==s[x] ? x : findset(s[x]);
}
//查找。路径压缩版
int find_set(int x)
{
	if (x != s[x]) s[x] = find_set(s[x]);
	return s[x];
}
//查找。while循环版本
int findSet(int x)
{
	int r = x;
	while(s[x] != r) {
		r = s[r];
	}
	int i = x , j;
	while(i != r) {
		j = s[i];
		s[i] = r;
		i = j;
	}
	return r;
}
//合并
void merge_set(int x,int y)
{
	x = find_set(x);y = find_set(y);
	if (x != y) s[x] = s[y];
}
int main ()
{
	return 0;
}