/*
# U644849 poj1273排水系统--Ford-Fulkson

## 题目描述

农夫约翰建造了一个排水系统来排放他的农田中的雨水。这个排水系统由一系列排水管道和水池组成。

有 M 个水池（编号 1 到 M）和 N 条排水管道（编号 1 到 N）。水池 1 是源头（无限水源），水池 M
是汇点（最终排水口）。每条管道连接两个不同的水池，并且有一个最大排水容量。

现在需要计算从源头水池到汇点水池的最大排水速率。

## 输入格式

输入包含多个测试用例。

每个测试用例的格式如下：

第一行：两个整数 N, M，表示管道数量和水池数量。

接下来 N 行：每行三个整数 S, E, C，表示一条从水池 S 到水池 E 的管道，最大排水容量为 C。

当 N = 0 且 M = 0 时，输入结束。

注意：水池编号从 1 开始。题目保证不会同时出现两条起点和终点都相同的管道。

## 输出格式

对于每个测试用例，输出一个整数，表示从水池 1 到水池 M 的最大排水速率。

## 输入输出样例 #1

### 输入 #1

```
5 4
1 2 40
1 4 20
2 4 20
2 3 30
3 4 10
```

### 输出 #1

```
50
```
 */
#include <iostream>
#include <iomanip>
#include <array>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <string>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <climits>
#include <cstring>
using namespace std;
#define int long long


const int MAXN = 205;
const int INF  = 0x3f3f3f3f;

int N, M;
int edge[MAXN][MAXN];
bool visited[MAXN];

int dfs(int u, int t, int flow) {
    if (u == t)
        return flow;
    visited[u] = true;
    for (int v = 1; v <= M; v++) {
        if (!visited[v] && edge[u][v]) {
            int d = dfs(v, t, min(flow, edge[u][v]));
            if (d > 0) {
                edge[u][v] -= d;
                edge[v][u] += d;
                return d;
            }
        }
    }
    return 0;
}

int f(int s, int t) {
    int ans = 0;
    while (true) {
        memset(visited, 0, sizeof(visited));
        int a = dfs(s, t, INF);
        if (a == 0)
            break;
        ans += a;
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while (cin >> N >> M && N && M) {
        memset(edge, 0, sizeof(edge));
        for (int i = 0; i < N; i++) {
            int s, e, c;
            cin >> s >> e >> c;
            edge[s][e] = c;
        }
        cout << f(1, M) << "\n";
    }

    return 0;
}
