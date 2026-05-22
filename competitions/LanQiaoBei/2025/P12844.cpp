#include <iostream>
using namespace std;
#define int uint64_t
int n;
const int N = 3e5 + 5;
int head[N];
struct _ed {
    int next;
    int to;
} edge[N];
int num[N];
int childnum[N];

int ans;
int visited;
void dfs(int u) {
    ++visited;
    for (int i = head[u]; i != 0; i = edge[i].next) {
        dfs(edge[i].to);
        ++childnum[u];
    }
}
int root;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; ++i) {
        int a, b;
        cin >> a >> b;
        edge[i].to   = b;
        edge[i].next = head[a];
        head[a]      = i;
        ++num[a];
    }
    for (int i = 1; i <= n; ++i) {
        if (num[i] == 0) {
            root = i;
            break;
        }
    }

    dfs(root);
    return 0;
}
