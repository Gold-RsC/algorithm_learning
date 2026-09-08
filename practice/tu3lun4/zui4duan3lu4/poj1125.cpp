/*
# U644842 poj1125 股票经纪人传播谣言

## 题目描述

股票经纪人之间传递谣言。你需要编写一个程序，选择一个股票经纪人作为谣言的起点，使得谣言传播到所有其他经纪人所需的时间最少。

有 n 个股票经纪人（1 ≤ n ≤
100）。每个经纪人与一些其他经纪人有联系，当谣言传递给一个经纪人后，他可以在一定时间内将谣言传给他联系的其他经纪人。

对于每个经纪人 i，你会先知道他的联系人数量 m，然后是 m 对整数 (t, w)，表示经纪人 i 可以花费 w 分钟将谣言传给经纪人 t。

注意：谣言可以同时沿着不同的路径传播。

## 输入格式

输入包含多个测试用例。

对于每个测试用例：

第一行：一个整数 n，表示经纪人的数量。

接下来 n 部分：每部分描述一个经纪人的联系人：

第一行：一个整数 m，表示该经纪人的联系人数量。

接下来 m 行：每行两个整数 t 和 w，表示可以传给经纪人 t，需要 w 分钟。

当 n = 0 时，输入结束。

## 输出格式

对于每个测试用例，输出一行：

如果可以传播给所有人：输出起始经纪人编号和所需的最少时间（单位：分钟）。

如果有人无法收到谣言：输出 disjoint。

## 输入输出样例 #1

### 输入 #1

```
3
2 2 4 3 5
2 1 2 3 6
2 1 2 2 2
5
3 4 4 2 8 5 3
1 5 8
4 1 6 4 10 2 7 5 2
0
2 2 5 1 5
0
```

### 输出 #1

```
3 2
3 10
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

const int INF = 0x3f3f3f3f;
const int N   = 105;

int n;
int d[N][N];

void f() {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while (cin >> n && n) {
        memset(d, 0x3f, sizeof(d));
        for (int i = 0; i < n; ++i) {
            int m;
            cin >> m;
            for (int j = 0; j < m; ++j) {
                int t, w;
                cin >> t >> w;
                d[i][t - 1] = w;
            }
            d[i][i] = 0;
        }

        f();

        int ans1 = 101, ans2 = INF;
        for (int i = 0; i < n; ++i) {
            int maxtime = 0;
            for (int j = 0; j < n; ++j) {
                if (d[i][j] == INF) {
                    cout << "disjoint\n";
                    return 0;
                }
                maxtime = max(maxtime, d[i][j]);
            }
            if (maxtime < ans2) {
                ans2 = maxtime;
                ans1 = i + 1;
            }
        }
        cout << ans1 << " " << ans2 << "\n";
    }


    return 0;
}
