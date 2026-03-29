#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int n, m, k;
vector<vector<bool>> _map;
vector<vector<uint16_t>> visited;
// pos[x,y],step
bool query(pair<int, int> pos) {
    return _map[pos.first][pos.second];
}
bool outofrange(pair<int, int> pos) {
    return pos.first < 0 || pos.first >= n || pos.second < 0 || pos.second >= m;
}
struct Node {
    pair<int, int> pos;
    int step;
};
pair<int, int> END;
int min_step = INT_MAX;
void dfs(Node x) {
    if (outofrange(x.pos)) {
        return;
    }


    if (visited[x.pos.first][x.pos.second] & (1 << (x.step % k + 1))) {

        return;
    }
    bool to_check = _map[0][0] ^ ((x.step / k) & 1);
    if (_map[x.pos.first][x.pos.second] != to_check) {

        return;
    }
    if (x.pos == END) {
        min_step = min(min_step, x.step);
        return;
    }
    visited[x.pos.first][x.pos.second] |= (1 << (x.step % k + 1));
    dfs({{x.pos.first + 1, x.pos.second}, x.step + 1});
    dfs({{x.pos.first, x.pos.second + 1}, x.step + 1});
    dfs({{x.pos.first - 1, x.pos.second}, x.step + 1});
    dfs({{x.pos.first, x.pos.second - 1}, x.step + 1});
    visited[x.pos.first][x.pos.second] &= ~((1 << (x.step % k + 1)));
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    _map    = vector<vector<bool>>(n, vector<bool>(m, false));
    visited = vector<vector<uint16_t>>(n, vector<uint16_t>(m, 0));
    END     = {n - 1, m - 1};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c;
            cin >> c;
            _map[i][j] = (c == 'A');
        }
    }
    dfs({{0, 0}, 0});
    if (min_step == INT_MAX) {
        cout << -1;
    }
    else {
        cout << min_step;
    }


    return 0;
}
