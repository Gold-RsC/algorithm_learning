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
const int N = 5e4 + 5;

int n, m;
int sqrtn;
int block(int x) {
    return x / sqrtn;
}
struct Query {
    int l, r;
    int id;

    int len() const {
        return (r - l + 1);
    }

    bool operator<(const Query& _) const {
        if (block(l) != block(_.l)) {
            return l < _.l;
        }
        return (block(l) & 1) ? r < _.r : r > _.r;
    }
} q[N];
int c[N];
struct Ans {
    int num, den;
} ans[N];

int curL = 1, curR = 0;

int cnt[N];  // 对饮颜色的袜子在[curL,curR]的数量
int sum;     // 拿到同色袜子的方案数
void add(int x) {
    sum += cnt[x];
    ++cnt[x];
}
void del(int x) {
    --cnt[x];
    sum -= cnt[x];
}

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}
int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    sqrtn = sqrt(n);
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }
    for (int i = 1; i <= m; ++i) {
        cin >> q[i].l >> q[i].r;
        q[i].id = i;
    }

    sort(q + 1, q + m + 1);

    for (int i = 1; i <= m; ++i) {
        if (q[i].l == q[i].r) {
            ans[q[i].id].num = 0;
            ans[q[i].id].den = 1;
            continue;
        }

        while (curL > q[i].l)
            add(c[--curL]);
        while (curR < q[i].r)
            add(c[++curR]);
        while (curL < q[i].l)
            del(c[curL++]);
        while (curR > q[i].r)
            del(c[curR--]);

        ans[q[i].id].num = sum;
        ans[q[i].id].den = q[i].len() * (q[i].len() - 1) / 2;
    }
    for (int i = 1; i <= m; ++i) {
        int g = gcd(ans[i].num, ans[i].den);
        ans[i].num /= g, ans[i].den /= g;
        cout << ans[i].num << "/" << ans[i].den << endl;
    }


    return 0;
}
