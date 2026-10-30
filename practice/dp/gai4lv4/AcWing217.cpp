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
#include <cstdint>
using namespace std;
#define int long long
const int N = 2e5 + 5;
struct Edge {
    int next;
    int to;
    int weight;
};
vector<Edge> edge;
vector<int> head(N, -1);
vector<int> sz(N, 0);
void init_edge() {
    edge.clear();
    fill(head.begin(), head.end(), -1);
}
void add_edge(int u, int v, int w) {
    edge.push_back({head[u], v, w});
    head[u] = edge.size() - 1;
    sz[u]++;
}

int n, m;

double f[N];

double dfs(int u) {
    if (u == n) {
        return 0;
    }
    if (f[u]) {
        return f[u];
    }

    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].to;
        int w = edge[i].weight;

        f[u] += (dfs(v) + w) * 1.0 / sz[u];
    }
    return f[u];
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        add_edge(a, b, c);
    }
    cout << fixed << setprecision(2) << dfs(1);


    return 0;
}
