#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>
template <typename T>
struct Fenwick {    //树状数组
    int n;
    std::vector<T> a;
    
    Fenwick(int n = 0) {
        init(n);
    }
    
    void init(int n) {
        this->n = n;
        a.assign(n, T());
    }
    
    void add(int x, T v) {
        for (int i = x + 1; i <= n; i += i & -i /*lowbit*/) {
            a[i - 1] += v;
        }
    }
    
    T sum(int x) {
        auto ans = T();
        for (int i = x; i > 0; i -= i & -i) {
            ans += a[i - 1];
        }
        return ans;
    }
    
    T rangeSum(int l, int r) {  //查询区间(l,r)
        return sum(r) - sum(l);
    }
    //解决RMQ
    //第 k 小元素查询方法（int kth(T k)）：找到使得前 x 个元素和不超过给定值 k 的最大 x 值，实际上用于定位数组中的第 k 小元素。
    int kth(T k) {
        int x = 0;
        for (int i = 1 << (int)std::log2(n); i; i /= 2) {
            if (x + i <= n && k >= a[x + i - 1]) {
                x += i;
                k -= a[x - 1];
            }
        }
        return x;
    }
};
int main ()
{
    return 0;
}