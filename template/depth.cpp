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
    int weight;
};
vector<Edge> edge;

vector<int> head(N, -1);

void init_edge() {
    edge.clear();
    fill(head.begin(), head.end(), -1);
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


/**
 * @brief depth和father
 * @param d[x]:表示x深度
 * @param f[x][k]:表示x的2^k辈祖先
 * @details time O(n)
 */

int d[N];
int f[N][LOGN];


void prework(int root) {
    queue<int> q;
    q.push(root);
    d[root] = 1;
    int t   = (int)(log(n) / log(2)) + 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = head[u]; ~i; i = edge[i].next) {
            int v = edge[i].to;
            int w = edge[i].weight;
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
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    return 0;
}
