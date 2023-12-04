#include <iostream>
#include <cmath>
//只能解决RMQ问题
//查询最大值的话就把所有min函数改成max
//如果元素出现修改的情况请使用Fenwick或线段树
using namespace std;
const int MAXN = 1000; // 假定数组大小不超过1000
int arr[MAXN];
int table[MAXN][20];
int Log2[MAXN];
void buildSparseTable(int n) 
{
    int k = Log2[n] + 1;
    // 计算Log2数组，用于快速计算区间大小的对数
    Log2[1] = 0;
    for (int i = 2; i <= n; i++) {
        Log2[i] = Log2[i>>1] + 1;
    }
    // 初始化第0列（区间长度为1的情况）
    for (int i = 0; i < n; i++) {
        table[i][0] = arr[i];
    }
    // 填充其余的列
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            // 使用递推公式，计算两个区间的最小值
            table[i][j] = min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int query(int l, int r) 
{
    int k = Log2[r - l + 1];
    return min(table[l][k], table[r - (1 << k) + 1][k]);
}

int main() 
{
    int n = 8; // 数组大小
    arr[0] = 2;
    arr[1] = 4;
    arr[2] = 3;
    arr[3] = 1;
    arr[4] = 6;
    arr[5] = 7;
    arr[6] = 8;
    arr[7] = 9;

    buildSparseTable(n);

    int l = 1;
    int r = 5;
    int min_val = query(l, r);
    cout << "最小值: " << min_val << endl;

    return 0;
}