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
#define is_equal(a, b) (fabs(a - b) < 1e6)

struct Point {
    int x, y;
    size_t hash() {
        return (x - 1) ^ (y << 1);
    }
};
typedef pair<Point, Point> PP;
typedef pair<Point, uint64_t> PL;
template <>
struct std::hash<PP> {
    size_t operator()(PP p) const {
        return p.first.hash() ^ p.second.hash();
    }
};
const int N = 2005;
int n;
Point v[N];

unordered_multimap<uint64_t, int> lp[N];

bool isnt_line(uint64_t x1,
               uint64_t y1,
               uint64_t x2,
               uint64_t y2) {
    return x1 * y2 != x2 * y1;
}
int ans;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i].x >> v[i].y;
        for (int j = 1; j < i; ++j) {
            uint64_t x = v[i].x - v[j].x;
            uint64_t y = v[i].y - v[j].y;
            uint64_t l = x * x + y * y;

            auto be   = lp[i].equal_range(l);
            bool flag = true;

            for (auto it = be.first; it != be.second;
                 ++it) {
                // cerr << "i " << i << " j " << j << endl;
                uint64_t xp = v[i].x - v[it->second].x;
                uint64_t yp = v[i].y - v[it->second].y;
                if (isnt_line(xp, yp, x, y)) {
                    ++ans;
                }
                else {
                    flag = false;
                }
            }
            be = lp[j].equal_range(l);


            for (auto it = be.first; it != be.second;
                 ++it) {
                // cerr << "i " << i << " j " << j << endl;
                uint64_t xp = v[j].x - v[it->second].x;
                uint64_t yp = v[j].y - v[it->second].y;
                if (isnt_line(xp, yp, x, y)) {
                    ++ans;
                }
                else {
                    flag = false;
                }
            }

            lp[i].insert({l, j});
            lp[j].insert({l, i});
        }
    }
    cout << ans;

    return 0;
}
