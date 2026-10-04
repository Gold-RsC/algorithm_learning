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

const int N = 1e5 + 5;

/**
 * @note 两个v-BCC最多有一个公共点，其为割点
 * @note v-BCC在dfs搜索树中dfn最小的点 一定是割点或树根
 *       1. 当这个点为割点时，一定是点双连通分量的根
 *       2. 当这个点为树根时，
 *          a. 有两个以上的子树，那他一定是割点
 *          b. 只有一个子树，那他是一个点双连通分量的根
 *          c. 没有子树，那他自己成为一个点双连通分量
 * @details O(V+E)
 */
struct Edge {
    int next;
    int to;
};
vector<Edge> edge;
vector<int> head(N, -1);
void init_edge() {
    edge.clear();
    fill(head.begin(), head.end(), -1);
}
void add_edge(int u, int v) {
    edge.push_back({head[u], v});
    head[u] = edge.size() - 1;
    edge.push_back({head[v], u});
    head[v] = edge.size() - 1;
}

int dfn[N];
int low[N];
int timestamp;

bool is_cut[N];

int root;  // 此时dfs搜索树是以谁为root
stack<int> s;

int BCC_count;       // v-BCC个数
vector<int> BCC[N];  // BCC[i]表示第i个v-BCC，注：有些割点是重复的

void tarjan(int u) {
    dfn[u] = low[u] = ++timestamp;
    s.push(u);

    int child_num = 0;  // 记录满足low[v]>=dfn[u]的子节点个数
    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].to;

        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
            // 判据：无法回溯到更早的地方，则u一定是一个割点或根节点
            if (low[v] >= dfn[u]) {
                // 如果不是树根，一定为割点；如果有两个以上的子树，则一定为割点
                if (++child_num > 1 || u != root) {
                    is_cut[u] = true;
                }

                // 说明发现v-BCC
                ++BCC_count;
                int x;
                do {
                    x = s.top();
                    s.pop();
                    BCC[BCC_count].push_back(x);
                } while (x != v);
                BCC[BCC_count].push_back(u);
            }
        }
        else {
            low[u] = min(low[u], dfn[v]);
        }
    }
}
void solve() {
    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) {
            if (~head[i]) {
                while (!s.empty()) {
                    s.pop();
                }
                root = i;
                tarjan(i);
            }
            else {
                dfn[i] = low[i] = ++timestamp;
                ++BCC_count;
                BCC[BCC_count].push_back(i);
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);


    return 0;
}
