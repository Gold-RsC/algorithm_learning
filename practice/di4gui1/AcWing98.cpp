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
#define int uint64_t


struct Point {
    int x, y;
    void rotate(int a, int n) {
        // cerr << "$" << a << endl;
        switch (a) {
            case 0: {
                swap(x, y);
                break;
            }
            case 1: {
                break;
            }
            case 2: {
                break;
            }
            case 3: {
                x = (1ull << (n)) - 1 - x;
                y = (1ull << (n)) - 1 - y;
                swap(x, y);
                break;
            }
        }
    }
};
ostream& operator<<(ostream& os, const Point& a) {
    return os << "[" << a.x << " " << a.y << "]";
}
Point calc(int n, int a) {
    if (n == 1) {
        switch (a) {
            case 0: {
                return {0, 0};
            }
            case 1: {
                return {1, 0};
            }
            case 2: {
                return {1, 1};
            }
            case 3: {
                return {0, 1};
            }
        }
        return {(int)-1, (int)-1};
    }
    // 所在的n-1级城市在n级城市中的位置
    Point pos_city = calc(1, a / (1ull << ((n - 1) << 1)));
    // cerr << "{" << n << "," << pos_city << "}";
    // 在n-1级城市中的位置
    // cerr << "(" << n << "," << a % (1 << ((n - 1) << 1)) << ")";
    Point pos_1 = calc(n - 1, a % (1ull << ((n - 1) << 1)));
    // 旋转
    // cerr << "<" << n << "," << pos_1 << ">";
    pos_1.rotate(a / (1ull << ((n - 1) << 1)), n - 1);
    // cerr << "<" << n << "," << pos_1 << ">";
    return {(pos_city.x << (n - 1)) + pos_1.x, (pos_city.y << (n - 1)) + pos_1.y};
}
double dis(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}


void solve(int n, int a, int b) {
    // cerr << calc(n, a) << " " << calc(n, b) << endl;
    cout << fixed << setprecision(0) << 10 * dis(calc(n, a), calc(n, b)) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    while (n--) {
        int N, A, B;
        cin >> N >> A >> B;
        // cout << N << " " << A << " " << B << endl;
        solve(N, A - 1, B - 1);
    }

    return 0;
}
