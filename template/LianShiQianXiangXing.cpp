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
using namespace std;

vector<bool> visited;

struct Edge {
    int next;    // 下一个坐标
    int to;      // 指向的节点
    int weight;  // 权重
};
vector<Edge> edge;

vector<int> head;  // 头节点的初始坐标

vector<int> head_list;  // 可要可不要，头节点的集合

void add(int u, int v, int w) {
    edge.push_back({head[u], v, w});
    head[u] = edge.size() - 1;
}

bool find_edge(int u, int v) {
    // ~i 表示 i != -1
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
        dfs(edge[i].to);
    }
}
vector<int> find_root() {
    vector<int> in_degree(head.size(), 0);

    for (auto e : edge) {
        ++in_degree[e.to];
    }

    vector<int> root_list;
    for (int x : head_list) {
        if (in_degree[x] == 0) {
            root_list.push_back(x);
        }
    }
    return root_list;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    return 0;
}
