/*
# U692921 POJ 1084 破坏正方形

## 题目描述

下图左边显示了一个由 2×(3×4) = 24 根火柴组成的完整 3×3 网格。所有火柴的长度均为
1。你可以在网格中找到许多不同大小的正方形。正方形的大小由其边长定义。在左图所示的网格中，有 9 个边长为 1 的正方形，4
个边长为 2 的正方形，以及 1 个边长为 3 的正方形。

完整网格中的每根火柴都有一个唯一的编号，编号按从左到右、从上到下的顺序分配，如左图所示。如果你从完整网格中移除一些火柴，那么网格中的某些正方形就会被破坏。右图显示了一个不完整的
3×3 网格，其中移除了编号为 12、17 和 23 的三根火柴。这次移除了 5 个边长为 1 的正方形、3 个边长为 2 的正方形和 1 个边长为
3 的正方形。因此，这个不完整的网格不再有边长为 3 的正方形，但仍然有 4 个边长为 1 的正方形和 1 个边长为 2 的正方形。

## 输入格式

输入包含 T 个测试用例。

第一行包含一个整数 T，表示测试用例的数量。

每个测试用例包含两行：

第一行包含一个自然数 n（n ≤ 5），表示你将得到一个 n×n 的网格。

第二行以一个非负整数 k 开头，表示完整 n×n 网格中缺失的火柴数量，随后是 k 个整数，表示缺失的火柴编号。如果 k =
0，表示输入网格是完整的。

## 输出格式

对于每个测试用例输出一行，包含需要移除的、用以破坏输入网格中所有正方形的最少火柴数量。

## 输入输出样例 #1

### 输入 #1

```
2
2
0
3
3 12 17 23
```

### 输出 #1

```
3
3
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

int n, k;
bool match[100];              // 火柴是否存在，编号从1开始
vector<vector<int>> squares;  // 每个正方形的火柴编号列表
int maxDepth;

// 预处理所有正方形
void initSquares() {
    squares.clear();
    int totalMatches = 2 * n * (n + 1);
    // 水平火柴编号: 1 ~ n*(n+1)
    // 垂直火柴编号: n*(n+1)+1 ~ 2n(n+1)
    auto hor = [&](int r, int c) {  // 第r行(0~n), 第c列(0~n-1)的水平火柴
        return r * n + c + 1;
    };
    auto ver = [&](int r, int c) {  // 第r行(0~n-1), 第c列(0~n)的垂直火柴
        return n * (n + 1) + c * n + r + 1;
    };
    for (int s = 1; s <= n; s++) {  // 边长
        for (int r = 0; r + s <= n; r++) {
            for (int c = 0; c + s <= n; c++) {
                vector<int> m;
                // 上边
                for (int i = 0; i < s; i++)
                    m.push_back(hor(r, c + i));
                // 下边
                for (int i = 0; i < s; i++)
                    m.push_back(hor(r + s, c + i));
                // 左边
                for (int i = 0; i < s; i++)
                    m.push_back(ver(r + i, c));
                // 右边
                for (int i = 0; i < s; i++)
                    m.push_back(ver(r + i, c + s));
                squares.push_back(m);
            }
        }
    }
}

// 检查正方形是否完整
bool isComplete(const vector<int>& sq) {
    for (int m : sq)
        if (!match[m])
            return false;
    return true;
}

// 获取当前所有完整正方形
vector<int> getCompleteSquares() {
    vector<int> res;
    for (int i = 0; i < (int)squares.size(); i++) {
        if (isComplete(squares[i]))
            res.push_back(i);
    }
    return res;
}

// IDA* 搜索
bool dfs(int depth, vector<int>& completeSq) {
    if (completeSq.empty())
        return true;  // 所有正方形已破坏
    if (depth == maxDepth)
        return false;

    // 启发式：选择包含火柴最少的完整正方形
    int bestSq = -1, minMatches = INT_MAX;
    for (int idx : completeSq) {
        if ((int)squares[idx].size() < minMatches) {
            minMatches = squares[idx].size();
            bestSq     = idx;
        }
    }
    if (bestSq == -1)
        return true;

    // 尝试移除该正方形中的每一根火柴
    for (int m : squares[bestSq]) {
        if (!match[m])
            continue;  // 已经移除
        match[m] = false;
        // 更新完整正方形列表
        vector<int> newComplete;
        for (int idx : completeSq) {
            if (isComplete(squares[idx]))
                newComplete.push_back(idx);
        }
        if (dfs(depth + 1, newComplete))
            return true;
        match[m] = true;  // 回溯
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        cin >> k;
        // 初始化所有火柴存在
        fill(match, match + 100, true);
        for (int i = 0; i < k; i++) {
            int x;
            cin >> x;
            match[x] = false;
        }
        initSquares();
        vector<int> completeSq = getCompleteSquares();
        if (completeSq.empty()) {
            cout << 0 << '\n';
            continue;
        }
        // 迭代加深
        for (maxDepth = 0;; maxDepth++) {
            if (dfs(0, completeSq)) {
                cout << maxDepth << '\n';
                break;
            }
        }
    }
    return 0;
}
