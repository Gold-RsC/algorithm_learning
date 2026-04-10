// OI
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <climits>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    return 0;
}

//__int128
istream& operator>>(istream& is, __int128& a) {
    char ch;
    is.get(ch);
    __int128 f = 1, x = 0;
    while (ch < '0' || ch > '9') {
        if (ch == '-') {
            f = -1;
        }
        is.get(ch);
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + (ch - '0');
        is.get(ch);
    }
    a = f * x;
    return is;
}
ostream& operator<<(ostream& os, __int128 x) {
    if (x < 0) {
        os << '-';
        x = -x;
    }
    if (x > 9) {
        os << (x / 10);
    }
    os << char((x % 10) + '0');
    return os;
}

// DSU
struct DSU {
    vector<int> parent, size;
    DSU(int n)
        : parent(n),
          size(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        return x == parent[x] ? x
                              : parent[x] = find(parent[x]);
    }
    void unite(int x, int y) {
        x = find(x), y = find(y);
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

// gcd
int gcd(int x, int y) {
    return y ? gcd(y, x % y) : x;
}
int lcm(int x, int y) {
    return x / gcd(x, y) * y;
}

// lianshiqianxiangxing
struct Edge {
    int v, w;
    int next;
};
vector<Edge> edge;
vector<int> head(N, -1);

void init() {
    head.resize(n, -1);
}

void add(int u, int v, int w) {
    edge.push_back({v, w, head[u]});
    head[u] = edge.size() - 1;
}

void dfs(int u) {
    if (visited[u]) {
        return;
    }
    visited[u] = true;
    for (int i = head[u]; ~i; i = edge[i].next) {
        dfs(edge[i].v);
    }
}
bool find_edge(int u, int v) {
    for (int i = head[u]; ~i; i = edge[i].next) {
        if (edge[i].v == v) {
            return true;
        }
    }
    return false;
}

// linjiejuzhen
int weight[N][N];

// linjielianbiao
struct Edge {
    int v, w;
};
vector<Edge> edge[N];


// qpow
int qpow(int a, int n, int MOD) {
    int ans = 1;
    while (n) {
        if (n & 1) {
            ans = ans * a % MOD;
        }
        a = a * a % MOD;
        n >>= 1;
    }
    return ans;
}

// SPFA
struct Edge {
    int v, w;
};
vector<Edge> edge[N];
int dist[N];
int cnt[N];
bool vis[N];

queue<int> q;

bool SPFA(int s) {
    memset(dist, 0x3f, (n + 1) * sizeof(dist[0]));

    dis[s] = 0;
    vis[s] = true;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = false;

        for (auto e : edge[u]) {
            int v = e.v, w = e.w;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                if (cnt[v] >= n) {
                    return true;
                }
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
    return false;
}

// dijkstra
struct Edge {
    int v, w;
};
vector<Edge> edge[N];
int dis[N];
bool vis[N];
struct Node {
    int dis, pos;
    bool operator>(const Node& a) const {
        return this->dis > a.dis;
    }
};
priority_queue<Node, vector<int>, greater<Node>> pq;
void Dijkstra(int s) {
    memset(dis, 0x3f, (n + 1) * sizeof(dis[0]));
    dis[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        int u = pq.top().pos;
        pq.pop();
        if (vis[u]) {
            continue;
        }
        vis[u] = true;
        for (auto e : edge[u]) {
            int v = e.v, w = e.w;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                // 只可能在更新的地方发生变化
                pq.push({dis[v], v});
            }
        }
    }
}
