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
const int N    = 10010;
const int LOGN = 15;
struct Edge {
    int next;
    int to;
};
vector<Edge> edge;

vector<int> head(N, -1);
unordered_map<int, int> weight_to_idx;
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
int n;
int f[N][LOGN];
int d[N];

int a[N];  // ÖÐÐò

int b[N];  // Ç°Ðò

void prework(int root) {
    queue<int> q;
    q.push(root);

    d[root] = 1;

    int t = (int)(log(n) / log(2)) + 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = head[u]; ~i; i = edge[i].next) {
            int v = edge[i].to;
            if (d[v]) {
                continue;
            }
            q.push(v);

            d[v] = d[u] + 1;

            f[v][0] = u;
            for (int j = 1; j <= t; ++j) {
                f[v][j] = f[f[v][j - 1]][j - 1];
            }
        }
    }
}
int lca(int x, int y) {
    if (d[x] > d[y]) {
        swap(x, y);
    }
    int t = (int)(log(n) / log(2)) + 1;

    for (int i = t; i >= 0; --i) {
        if (d[f[y][i]] >= d[x]) {
            y = f[y][i];
        }
    }
    if (x == y) {
        return x;
    }
    for (int i = t; i >= 0; --i) {
        if (f[x][i] != f[y][i]) {
            x = f[x][i];
            y = f[y][i];
        }
    }
    return f[x][0];
}

void build(long long father, int a_begin, int a_end, int b_begin, int b_end) {
    if (a_begin == a_end || b_begin == b_end) {
        return;
    }
    int root  = b[b_begin];
    int a_mid = weight_to_idx[root];
    int b_mid = b_begin + 1 + a_mid - a_begin;

    if (father != LLONG_MAX) {
        // cerr << "build" << father << " " << root << endl;
        add_edge(weight_to_idx[father], weight_to_idx[root]);
    }


    build(root, a_begin, a_mid, b_begin + 1, b_mid);
    build(root, a_mid + 1, a_end, b_mid, b_end);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int m;
    cin >> m >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        weight_to_idx[a[i]] = i;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    build(LLONG_MAX, 1, n + 1, 1, n + 1);
    prework(weight_to_idx[b[1]]);


    while (m--) {
        int u, v;
        cin >> u >> v;
        if (weight_to_idx.count(u) == 0 && weight_to_idx.count(v) == 0) {
            cout << "ERROR: " << u << " and " << v << " are not found.\n";
        }
        else if (weight_to_idx.count(u) == 0) {
            cout << "ERROR: " << u << " is not found.\n";
        }
        else if (weight_to_idx.count(v) == 0) {
            cout << "ERROR: " << v << " is not found.\n";
        }
        else {
            int LCA = a[lca(weight_to_idx[u], weight_to_idx[v])];
            if (LCA == u) {
                cout << LCA << " is an ancestor of " << v << ".\n";
            }
            else if (LCA == v) {
                cout << LCA << " is an ancestor of " << u << ".\n";
            }
            else {
                cout << "LCA of " << u << " and " << v << " is " << LCA << ".\n";
            }
        }
    }

    return 0;
}
