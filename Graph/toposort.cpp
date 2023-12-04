#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 1e6+5;
vector<int>e[MAXN],tp;	//存邻接点
int n,din[MAXN];		//存点的入度
bool toposort () 
{
    queue<int>q;
    for (int i = 1 ; i <= n ; ++i ) {
        if (din[i] == 0) {
            q.push(i);
        }
    }
    while (q.size()) {
        int x = q.front();q.pop();
        tp.push_back(x);
        for (auto y : e[x]) {
            if (--din[y] == 0) {
                q.push(y);
            }
        }
    }
    return tp.size() == n;
}
int main ()
{
    int m;
    cin >> n >> m;
    for (int i = 0 ; i < m ; ++i ) {
        int a,b;
        cin >> a >> b;
        e[a].push_back(b);
        din[b]++;
    }
    if (toposort()) puts("-1");
    else {
        for (auto x : tp) printf("%d ",x);
    }
    return 0;
}