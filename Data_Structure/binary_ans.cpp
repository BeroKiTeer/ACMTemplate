//二分答案
#include <iostream>
using namespace std;
bool check(int x)
{
    return false;
    //....			//计算y
    //最大化：
	//return y <= C //x小，y小
	//return y >= C //x小, y大

    //最小化 
    //return y <= C //x大，y小
	//return y >= C //x大, y大
}
//最大化答案
int maxbfind(int left,int right) //二分答案left(上界)~right(下界)
{
    int l = left - 1,r = right + 1;
    while (l + 1 < r) {
        int mid = (l+r) >> 1;
        if (check(mid)) l = mid;    //最大化
        else r = mid;
    }
    return l;
}
//最小化答案
int minbfind(int left,int right)
{
    int l = left - 1 , r = right + 1;
    while (l + 1 < r) {
        int mid = (l + r) >> 1;     //最小化
        if (check(mid)) l = mid;
        else r = mid;
    }
    return r;
}
int main ()
{
    return 0;
}