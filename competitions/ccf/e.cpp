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
    int next;
    int to;
};
vector<Edge> edge;

vector<int> head(N, -1);
int n;
void init_edge() {
    edge.clear();
    fill(head.begin(), head.end(), -1);
}
void add_edge(int u, int v) {
    edge.push_back({head[u], v});
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

void dfs(int u) {
    if (visited[u]) {
        return;
    }
    visited[u] = true;
    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].to;
        int w = edge[i].weight;
        dfs(v);
    }
}

int X;

int lastans;
unordered_set<int> fix;

struct Travel {
    int u, v;
};
unordered_set<Travel> travel;


int solve(int u, int v) {
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    cin >> n >> X;

    for (int i = 0; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
        add_edge(v, u);
    }
    int k;
    cin >> k;
    while (k--) {
        int p;
        cin >> p;
        fix.insert(p);
    }
    int m;
    cin >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        travel.insert({u, v});
    }

    int q;
    cin >> q;
    while (q--) {
        int f;
        cin >> f;
        if (f == 1) {
            int u, v;
            cin >> u >> v;
            u ^= lastans * X;
            v ^= lastans * X;

            cout << lastans << endl;
        }
        else {
        }
    }


    return 0;
}
