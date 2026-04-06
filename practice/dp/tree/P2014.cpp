#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <string>
#include <cmath>
#include <climits>
using namespace std;

const int N = 305;

vector<int> e[N];


int s[N];

int n, m;

void add_edge(int u, int v) {
    e[u].push_back(v);
}

int dp[N][N][N];

void dfs(int u) {
    for (auto v : e[u]) {
        dfs(v);
    }
    // Ã»¶®£¡£¡£¡
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;


    s[0] = 0;
    for (int i = 1; i <= n; ++i) {
        int k;
        cin >> k >> s[i];

        add_edge(k, i);
    }

    for (int i = 1; i <= m; ++i) {
        dfs(0);
    }

    return 0;
}
