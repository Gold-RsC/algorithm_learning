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

/**
 * @brief Andrew算法
 * @details O(n log n)
 */
struct Point {
    int x, y;

    Point operator+(const Point& _) const {
        return Point{x + _.x, y + _.y};
    }
    Point operator-(void) const {
        return Point{-x, -y};
    }
    Point operator-(const Point& _) const {
        return *this + (-_);
    }
    int operator*(const Point& _) const {
        return x * _.y - _.x * y;
    }
};

vector<int> s;  // 单调栈，记录下标
vector<Point> p;
bool used[N];
void Andrew() {
    // 确定左下角和右下角，一定是凸包顶点
    sort(p.begin(), p.end(), [&](const Point& a, Point& b) -> bool {
        if (a.x != b.x) {
            return a.x < b.x;
        }
        return a.y < b.y;
    });

    // 下凸壳
    s.push_back(0);
    for (int i = 1; i < s.size(); ++i) {
        while (s.size() >= 2 && (p[s[s.size() - 1]] - p[s[s.size() - 2]]) * (p[i] - p[s[s.size() - 1]]) <= 0) {
            used[s.back()] = 0;
            s.pop_back();
        }
        used[i] = 1;
        s.push_back(i);
    }

    // 上凸壳
    int bottom_size = s.size();
    for (int i = s.size() - 1; i >= 2; --i) {
        if (!used[i]) {
            while (s.size() > bottom_size &&
                   (p[s[s.size() - 1]] - p[s[s.size() - 2]]) * (p[i] - p[s[s.size() - 1]]) <= 0) {
                used[s.back()] = 0;
                s.pop_back();
            }
            used[i] = 1;
            s.push_back(i);
        }
    }
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);


    return 0;
}
