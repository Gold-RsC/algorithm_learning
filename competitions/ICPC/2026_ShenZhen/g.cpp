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

int n, m, rs, cs;

void solve(void) {
    int n, m, rs, cs;
    cin >> n >> m >> rs >> cs;
    // vector<vector<bool>> visited(n + 1, vector<bool>(m + 1, false));
    vector<vector<char>> direction(n + 1, vector<char>(m + 1, 0));

    auto debug = [&]() {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cerr << direction[i][j] << ' ';
            }
            cerr << endl;
        }
    };
    // visited[rs][cs] = true;
    if (n & 1) {
        if (m & 1) {
            int x = 1, y = 1;
            for (; y < m; ++y) {
                direction[x][y] = 'R';
            }
            direction[x][y] = 'D';
            ++x;
            while (x < n - 1) {
                for (; y > 3; --y) {
                    direction[x][y] = 'L';
                }
                direction[x][y] = 'D';
                ++x;
                for (; y < m; ++y) {
                    direction[x][y] = 'R';
                }
                direction[x][y] = 'D';
                ++x;
            }
            direction[x][y] = 'D';
            ++x;
            direction[x][y] = 'L';
            --y;
            while (y > 2) {
                direction[x][y] = 'U';
                --x;
                direction[x][y] = 'L';
                --y;
                direction[x][y] = 'D';
                ++x;
                direction[x][y] = 'L';
                --y;
            }
            while (x > 3) {
                direction[x][y] = 'L';
                --y;
                direction[x][y] = 'U';
                --x;
                direction[x][y] = 'R';
                ++y;
                direction[x][y] = 'U';
                --x;
            }
            direction[x - 1][y] = 'L';

            direction[x][y] = 'C';
            --y;
            direction[x][y] = 'U';
            --x;
            direction[x][y] = 'U';
            --x;
        }
        else {
            int x = 1, y = 1;
            for (; x < n; ++x) {
                direction[x][y] = 'D';
            }
            for (; y < m; ++y) {
                direction[x][y] = 'R';
            }
            for (; x > 1; --x) {
                direction[x][y] = 'U';
            }
            direction[x][y] = 'L';
            --y;
            for (; y > 1;) {

                for (; x < n - 1; ++x) {
                    direction[x][y] = 'D';
                }
                direction[x][y] = 'L';
                --y;
                for (; x > 1; --x) {
                    direction[x][y] = 'U';
                }
                direction[x][y] = 'L';
                --y;
            }
        }
    }
    else {
        int x = 1, y = 1;
        for (; y < m; ++y) {
            direction[x][y] = 'R';
        }
        for (; x < n; ++x) {
            direction[x][y] = 'D';
        }
        for (; y > 1; --y) {
            direction[x][y] = 'L';
        }
        direction[x][y] = 'U';
        --x;
        for (; x > 1;) {


            for (; y < m - 1; ++y) {
                direction[x][y] = 'R';
            }
            direction[x][y] = 'U';
            --x;
            for (; y > 1; --y) {
                direction[x][y] = 'L';
            }
            direction[x][y] = 'U';
            --x;
        }
    }

    // debug();

    int hx = rs, hy = cs;
    bool change      = false;
    auto moveonestep = [&](int& x, int& y) {
        if (direction[x][y] == 'U') {
            --x;
        }
        else if (direction[x][y] == 'D') {
            ++x;
        }
        else if (direction[x][y] == 'L') {
            --y;
        }
        else if (direction[x][y] == 'R') {
            ++y;
        }
        else if (direction[x][y] == 'C') {
            if (change) {
                --x;
            }
            else {
                --y;
            }
        }
    };
    auto moveto = [&](int r, int c) {
        while (hx != r || hy != c) {
            if (direction[hx][hy] == 'C') {
                if (r == 2 && c == 2) {
                    change = true;
                }
                else {
                    change = false;
                }
                cout << (change ? 'U' : 'L');
            }
            else {
                cout << direction[hx][hy];
            }

            moveonestep(hx, hy);
        }
    };

    for (int i = 1; i < n * m; ++i) {
        int r, c;
        cin >> r >> c;

        moveto(r, c);
        cout << '\n';
        cout.flush();
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }


    return 0;
}
