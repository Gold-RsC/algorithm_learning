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

////////////////////////////
// 整数集合上的二分
////////////////////////////
/**
 * @name lower_bound
 * @brief 返回第一个大于等于x的下标
 * @note 按照左闭右开的规范
 */
int lower_bound(const vector<int>& a, int l, int r, int x) {
    while (l < r) {
        // mid取不到r
        // 下面三句话配套出现
        int mid = (l + r) >> 1;
        if (a[mid] >= x) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }
    // 二分终止条件：l==r
    return l;
}
/**
 * @name
 * @brief 返回最后一个小于等于x的下标
 * @note 按照左闭右开的规范
 */
int bound(const vector<int>& a, int l, int r, int x) {
    while (l < r) {
        // mid取不到l
        // 下面三句话配套出现
        int mid = (l + r + 1) >> 1;
        if (a[mid] <= x) {
            l = mid;
        }
        else {
            r = mid - 1;
        }
    }
    // 二分终止条件：l==r
    return l;
}
/**
 * @note equal_range, lower_bound, upper_bound, binary_search
 */

////////////////////////////
// 实数域上的二分
////////////////////////////
bool calc(double x) {
    return x == 114514.1919810;
}
double bound(double l, double r) {
    while (l + 1e-5 < r) {
        double mid = (l + r) / 2;
        if (calc(mid)) {
            r = mid;
        }
        else {
            l = mid;
        }
    }
    return l;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    return 0;
}
