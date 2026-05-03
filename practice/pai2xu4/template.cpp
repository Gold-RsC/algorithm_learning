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

/**
 * @name discrete
 * @brief 离散化
 */
vector<int> discrete(vector<int> a) {
    if (a.empty()) {
        return {};
    }
    sort(a.begin(), a.end());
    a.erase(std::unique(a.begin(), a.end()), a.end());
    vector<int> r;
    r.push_back(a.front());
    int last = a.front();
    for (auto x : a) {
        if (last != x) {
            r.push_back(x);
            last = x;
        }
    }
    return r;
}

/**
 * @note 中位数到所有点的距离之和最小
 */


/**
 * @brief 排队型发牌问题(平分牌)
 * @param a 每个人的牌数，这里保证sum(a)%a.size()==0
 */
int fapai(vector<int> a) {
    int n   = a.size();
    int sum = 0;
    for (auto x : a) {
        sum += x;
    }
    int avr = sum / n;

    for (auto& x : a) {
        x -= avr;
    }

    int last_a = 0;
    vector<int> s;
    for (auto x : a) {
        s.push_back(x + last_a);
        last_a += x;
    }

    int ans = 0;
    for (auto x : s) {

        ans += abs(x);
    }
    return ans;
}
/**
 * @brief 循环型发牌问题(平分牌)
 * @param a 每个人的牌数，这里保证sum(a)%a.size()==0
 */
int fapai_xunhuan(vector<int> a) {
    int n   = a.size();
    int sum = 0;
    for (auto x : a) {
        sum += x;
    }
    int avr = sum / n;

    for (auto& x : a) {
        x -= avr;
    }

    int last_a = 0;
    vector<int> s;
    for (auto x : a) {
        s.push_back(x + last_a);
        last_a += x;
    }

    sort(s.begin(), s.end());
    int s_mid = s[s.size() / 2];
    int ans   = 0;
    for (auto x : s) {
        ans += abs(x - s_mid);
    }
    return ans;
}

/**
 * @brief 求逆序对=>归并排序
 */
int tmp[114514];

int merge(int a[], int l, int r) {  // 左闭右开
    int mid = (l + r) / 2;
    int cnt = 0;
    int i = l, j = mid;
    int k = l;
    while (i < mid && j < r) {
        if (a[i] <= a[j]) {
            tmp[k++] = a[i++];
        }
        else {
            tmp[k++] = a[j++];
            cnt += mid - i;
        }
    }
    while (i < mid) {
        tmp[k++] = a[i++];
    }
    while (j < r) {
        tmp[k++] = a[j++];
    }
    for (k = l; k < r; ++k) {
        a[k] = tmp[k];
    }
    return cnt;
}
int merge_sort(int a[], int l, int r) {
    if (r - l <= 1) {
        return 0;
    }
    int cnt = 0;
    int mid = (l + r) / 2;

    cnt += merge_sort(a, l, mid);
    cnt += merge_sort(a, mid, r);

    cnt += merge(a, l, r);
    return cnt;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    return 0;
}
