/*
# U730160 POJ 2186 Popular Cows

## 题目描述

每一头牛都梦想成为牛群里最受欢迎的牛。

牛群一共有 N 头牛。给出 M 组有序对 (A,B)，代表牛 A 认为牛 B 很受欢迎。

受欢迎关系具备传递性：
如果 A 认为 B 受欢迎，且 B 认为 C 受欢迎，那么 A 也会认为 C 受欢迎，哪怕输入没有直接给出这条关系。

## 输入格式

第一行两个整数 (N,M)。
接下来 M 行，每行两个整数 (A,B)，表示 A 认为 B 受欢迎。
注意：输入可能存在重复的 (A,B) 边。

## 输出格式

输出一个整数：被所有其他牛认为受欢迎的牛的数量。

## 输入输出样例 #1

### 输入 #1

```
3 3
1 2
2 1
2 3
```

### 输出 #1

```
1
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
#include <functional>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> g(N + 1);
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        g[A].push_back(B);
    }

    vector<int> dfn(N + 1, 0), low(N + 1, 0), scc(N + 1, 0);
    vector<int> st;
    vector<char> inStk(N + 1, 0);
    vector<int> sz(1, 0);  // 下标从 1 开始，sz[0] 占位

    int tim = 0, cnt = 0;

    function<void(int)> tarjan = [&](int u) {
        dfn[u] = low[u] = ++tim;
        st.push_back(u);
        inStk[u] = 1;

        for (int v : g[u]) {
            if (!dfn[v]) {
                tarjan(v);
                low[u] = min(low[u], low[v]);
            }
            else if (inStk[v]) {
                low[u] = min(low[u], dfn[v]);
            }
        }

        if (dfn[u] == low[u]) {
            ++cnt;
            sz.push_back(0);

            while (true) {
                int v = st.back();
                st.pop_back();
                inStk[v] = 0;
                scc[v]   = cnt;
                sz[cnt]++;
                if (v == u)
                    break;
            }
        }
    };

    for (int i = 1; i <= N; i++) {
        if (!dfn[i])
            tarjan(i);
    }

    vector<int> outdeg(cnt + 1, 0);

    for (int u = 1; u <= N; u++) {
        for (int v : g[u]) {
            if (scc[u] != scc[v]) {
                outdeg[scc[u]] = 1;
            }
        }
    }

    int zeroCnt = 0;
    int ans     = 0;

    for (int i = 1; i <= cnt; i++) {
        if (outdeg[i] == 0) {
            zeroCnt++;
            ans = sz[i];
        }
    }

    if (zeroCnt == 1)
        cout << ans << '\n';
    else
        cout << 0 << '\n';

    return 0;
}
