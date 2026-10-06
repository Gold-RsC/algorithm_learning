/**
 * @brief 整体二分+树状数组
 * @details 单点修改静态区间第k小
 * @details 给定长度为 n 的序列 a，m 次操作：Q l r k 查询区间 [l,r] 内第 k 小值；C x y 将 a_x 改为 y。
            输入：第一行 n,m；第二行 a_1,...,a_n；接下来 m 行每行一个操作 Q l r k 或 C x y。
            数据：1 ≤ n,m ≤ 1e5，1 ≤ l ≤ r ≤ n，1 ≤ k ≤ r?l+1，1 ≤ x ≤ n，0 ≤ a_i,y ≤ 1e9。
 * @note 也可使用离散化，但是不离散最多30层，不离散18层，只差常数级
 */
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
// #define int long long

const int N = 2e5 + 5;

int n;
//==================BIT===================
int lowbit(int x) {
    return x & (-x);
}
// int b[N];  // 原数组第i个位置的值，是否小于等于当前的mid
int c[N];  // 树状数组节点，c[i] 管理 (i - lowbit(i), i] 这段区间
// 单点更新
void add(int pos, int val) {
    for (int i = pos; i <= n; i += lowbit(i)) {
        c[i] += val;
    }
}
// 前缀和
int presum(int pos) {
    int res = 0;
    for (int i = pos; i > 0; i -= lowbit(i)) {
        res += c[i];
    }
    return res;
}
// 区间查询(左闭右闭)
int query(int left, int right) {
    return presum(right) - presum(left - 1);
}

//=================整体二分=====================

int a[N];  // 原数据


int m;


int ans[N];

struct Event {
    enum EventType {
        ADD,
        DELETE,
        QUERY
    } event_type;

    int l, r, k;  // query的内容
    int idx;      // 在对应数组中的idx
};
vector<Event> event;
vector<Event> leftE, rightE;

// el,er: Query的idx
// L,R: 值域
void solve(int el, int er, int L, int R) {
    if (el > er) {
        return;
    }

    if (L == R) {
        for (int i = el; i <= er; ++i) {
            if (event[i].event_type == Event::QUERY) {
                ans[event[i].idx] = L;
            }
        }
        return;
    }

    int MID = (L + R) >> 1;

    leftE.clear(), rightE.clear();
    for (int i = el; i <= er; ++i) {
        if (event[i].event_type == Event::QUERY) {
            auto& e = event[i];
            int cnt = query(e.l, e.r);
            if (cnt >= e.k) {
                leftE.push_back(event[i]);
            }
            else {
                e.k -= cnt;
                rightE.push_back(event[i]);
            }
        }
        else {
            auto& e = event[i];
            if (e.k <= MID) {
                add(e.idx, e.event_type == Event::ADD ? 1 : -1);
                leftE.push_back(e);
            }
            else {
                rightE.push_back(e);
            }
        }
    }

    // 只需要清空左半边的event即可，因为右半边的事件本来就不会被add进入
    for (const auto& e : leftE) {
        if (e.event_type == Event::ADD || e.event_type == Event::DELETE) {
            int idx = e.idx;
            if (e.k <= MID) {
                add(idx, e.event_type == Event::ADD ? -1 : 1);
            }
        }
    }

    int cnt = 0;
    for (const auto& x : leftE) {
        event[el + cnt] = x;
        cnt++;
    }
    int mid = el + cnt;
    for (const auto& x : rightE) {
        event[el + cnt] = x;
        cnt++;
    }
    solve(el, mid - 1, L, MID);
    solve(mid, er, MID + 1, R);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    //=================事件化==============
    for (int i = 1; i <= n; ++i) {
        Event e;
        e.event_type = Event::ADD;
        e.idx        = i;
        e.k          = a[i];
        event.push_back(e);
    }
    for (int i = 1; i <= m; ++i) {
        char c;
        cin >> c;
        if (c == 'C') {
            Event e;
            e.event_type = Event::DELETE;
            cin >> e.idx;
            e.k = a[e.idx];
            event.push_back(e);
            e.event_type = Event::ADD;
            cin >> e.k;
            a[e.idx] = e.k;

            event.push_back(e);
        }
        else {
            Event e;
            e.event_type = Event::QUERY;
            cin >> e.l >> e.r >> e.k;
            e.idx = i;
            event.push_back(e);
        }
    }

    fill(ans + 1, ans + m + 1, -1);

    solve(0, event.size() - 1, 0, 1e9 + 1);

    for (int i = 1; i <= m; ++i) {
        if (ans[i] != -1) {
            cout << ans[i] << endl;
        }
    }
    return 0;
}
