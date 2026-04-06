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
#include <climits>
using namespace std;

int m[6][6] = {
    {1, 0, 1, 0, -1, -1},
    {0, -1, -1, 0, -1, -1},
    {1, -1, -1, 1, 0, 0},
    {0, -1, -1, 1, -1, -1},
    {0, -1, 1, 0, -1, 1},
    {1, 0, 0, 1, 1, 0},
};

bool check() {
    // 1.
    for (int i = 0; i < 6; ++i) {
        int n = 0;
        for (int j = 0; j < 6; ++j) {
            if (m[i][j]) {
                ++n;
            }
        }
        if (n != 3) {
            return false;
        }
    }
    for (int i = 0; i < 6; ++i) {
        int n = 0;
        for (int j = 0; j < 6; ++j) {
            if (m[j][i]) {
                ++n;
            }
        }
        if (n != 3) {
            return false;
        }
    }

    // 2.
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j <= 3; ++j) {
            if (m[i][j] == m[i][j + 1] &&
                m[i][j] == m[i][j + 2]) {
                return false;
            }
            if (m[j][i] == m[j + 1][i] &&
                m[j][i] == m[j + 2][i]) {
                return false;
            }
        }
    }

    // 3.
    unordered_set<string> l;
    for (int i = 0; i < 6; ++i) {
        string s;
        for (int j = 0; j < 6; ++j) {
            s.push_back(m[i][j] ? '1' : '0');
        }
        if (l.size() && l.count(s)) {
            return false;
        }
        l.insert(s);
    }
    l.clear();
    for (int i = 0; i < 6; ++i) {
        string s;
        for (int j = 0; j < 6; ++j) {
            s.push_back(m[j][i] ? '1' : '0');
        }
        if (l.size() && l.count(s)) {
            return false;
        }
        l.insert(s);
    }
    return true;
}
uint64_t c;
bool dfs(int n) {
    if (n == 36) {
        cerr << ++c << " ";
        if (check()) {
            for (int i = 0; i < 6; ++i) {
                for (int j = 0; j < 6; ++j) {
                    cout << m[i][j] << " ";
                }
                cout << endl;
            }
            return true;
        }
        else {
            return false;
        }
    }
    int i = n / 6;
    int j = n % 6;
    if (m[i][j] != -1) {
        return dfs(n + 1);
    }
    m[i][j] = 1;
    if (dfs(n + 1)) {
        return true;
    }
    m[i][j] = 0;
    if (dfs(n + 1)) {
        return true;
    }
    m[i][j] = -1;
    return false;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    dfs(0);

    return 0;
}
