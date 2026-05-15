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
const int N = 1e4 + 5;
struct Edge {
    int next;
    int to;
    int weight;
};
vector<Edge> edge;

vector<int> head(N, -1);
vector<bool> isnot_root(N, 0);
void init_edge() {
    edge.clear();
    fill(head.begin(), head.end(), -1);
    fill(isnot_root.begin(), isnot_root.end(), 0);
}
void add_edge(int u, int v, int w) {
    edge.push_back({head[u], v, w});
    head[u] = edge.size() - 1;
}

bool find_edge(int u, int v) {
    for (int i = head[u]; ~i; i = edge[i].next) {
        if (edge[i].to == v) {
            return true;
        }
    }
    return false;
}

int ans = 0;
void dfs(int u) {


    for (int i = head[u]; ~i; i = edge[i].next) {
        dfs(edge[i].to);
    }
}


int n, k;

void solve() {
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while (1) {

        cin >> n >> k;
        if (n == 0 && k == 0) {
            break;
        }
        for (int i = 1; i < n; ++i) {
            int u, v, l;
            cin >> u >> v >> l;
            add(u, v, l);
            isnot_root[v] = true;
        }
        for (int i = 0; i < n; ++i) {
            if (!isnot_root[i]) {
                dfs(i);
                break;
            }
        }
    }


    return 0;
}
