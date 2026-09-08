/*
# U644846 poj3723 征召费用优化

## 题目描述

Windy 王国需要征召一些人员。现有 n 个女孩和 m
个男孩报名，需要征召其中一些人入伍。每个应征者有一个征召费用。另外，有一些特殊关系：某些女孩和某些男孩之间存在朋友关系。当征召一对有朋友关系的异性时，可以享受优惠，使得这两人的总征召费用减少。

现在需要征召一定数量的人员，问在可以选择征召任意人员的情况下，最小总费用是多少。

## 输入格式

第一行：一个整数 T，表示测试数据组数。
对于每组测试数据：

第一行：三个整数 n, m, r

接下来 r 行：每行三个整数 x, y, d，表示女孩 x 和男孩 y 之间存在朋友关系，如果同时征召女孩 x 和男孩
y，那么需要支付的费用为： 女孩 x 的费用 + 男孩 y 的费用 - d （其中每个人的基本征召费用为 10000）

## 输出格式

对于每组测试数据，输出一个整数，表示最小总费用。

## 输入输出样例 #1

### 输入 #1

```
1
5 5 8
4 3 6831
1 3 4583
0 0 6592
0 1 3063
3 3 4975
1 3 2049
4 2 2104
2 2 781
```

### 输出 #1

```
71071
```
*/

#include <iostream>
#include <iomanip>
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

struct Edge {
    // 女：u=x
    // 男: v=y+n
    int u, v, w;
    bool operator<(const Edge& b) const {
        return this->w < b.w;
    }
    bool operator>(const Edge& b) const {
        return this->w > b.w;
    }
};

struct DSU {
    vector<size_t> parent, size;
    DSU(size_t n)
        : parent(n),
          size(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    size_t find_root(size_t x) {
        return parent[x] == x ? x : parent[x] = find_root(parent[x]);
    }

    void unite(size_t x, size_t y) {
        x = find_root(x), y = find_root(y);
        if (x == y) {
            return;
        }
        if (size[x] < size[y]) {
            swap(x, y);
        }
        parent[y] = x;
        size[x] += size[y];
    }
};

void kruskal(int n, int m, vector<Edge>& edges) {
    DSU dsu(n + m);
    int tt  = 0;
    int cnt = 0;

    for (auto e : edges) {
        int u = e.u, v = e.v, w = e.w;

        int x = dsu.find_root(u);
        int y = dsu.find_root(v);
        if (x == y) {
            continue;
        }
        dsu.unite(x, y);
        tt += e.w;
        cnt++;

        if (cnt == n + m - 1) {
            break;
        }
    }

    cout << (n + m) * 10000 - tt << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int n, m, r;
        cin >> n >> m >> r;

        vector<Edge> edges;
        edges.reserve(r);

        for (int i = 0; i < r; ++i) {
            int x, y, d;
            cin >> x >> y >> d;

            // 女：x
            // 男: y+n
            edges.push_back({x, n + y, d});
        }
        sort(edges.begin(), edges.end(), greater<>());
        kruskal(n, m, edges);
    }

    return 0;
}
