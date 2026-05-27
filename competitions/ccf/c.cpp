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
#define int long long
const int INF = 5e5 + 10;
const int N   = 110;
struct JieKou {
    int a, L;
    int ptr;
};
struct JinCheng {
    vector<JieKou> jk;
};
JinCheng jc[N];

struct QuJian {
    int l, r;
};
bool operator<(const QuJian& a, const QuJian& b) {
    return a.l < b.l;
}
vector<QuJian> qj;
unordered_map<int, priority_queue<int, vector<int>, greater<int>>> ma;

void do_new(int p, int L) {
    int a = 0;
    if (ma.count(L)) {
    }
    else {
        for (auto it = qj.begin(); it != qj.end(); ++it) {
            auto& q = *it;
            if (q.r + 1 - q.l > L) {
                a     = q.l;
                q.l   = a + L;
                int x = ma[L].top();

                break;
            }
        }
    }
    jc[p].jk.push_back({a, L, -1});
    cout << a << endl;
    // for (auto c : qj) {
    //     // cerr << "[" << c.l << " " << c.r << "]" << endl;
    // }
}
void do_send(int p) {
    int ans = 0;
    for (auto& jk : jc[p].jk) {

        jk.ptr = (jk.ptr + 1) % jk.L;
        // cerr << "^" << jk.ptr << " " << jk.a << endl;
        // cerr << "$" << jk.ptr + jk.a << endl;
        ans += jk.ptr + jk.a;
    }
    cout << ans << endl;
}
void do_delete(int p, int i) {
    auto& jk = jc[p].jk[i - 1];

    auto it = lower_bound(qj.begin(), qj.end(), QuJian{jk.a, 114514});
    // cerr << it - qj.begin();
    if (it->l == jk.a + jk.L) {
        if (it == qj.begin()) {
            it->l = jk.a;
        }
        else {
            if ((it - 1)->r + 1 == jk.a) {
                (it - 1)->r = it->r;
                qj.erase(it);
            }
            else {
                it->l = jk.a;
            }
        }
    }
    else {
        if (it == qj.begin()) {
            qj.insert(it, {jk.a, jk.a + jk.L - 1});
        }
        else {
            if ((it - 1)->r + 1 == jk.a) {
                (it - 1)->r = jk.a + jk.L - 1;
            }
            else {
                qj.insert(it, {jk.a, jk.a + jk.L - 1});
            }
        }
    }
    jc[p].jk.erase(jc[p].jk.begin() + i - 1);


    // for (auto c : qj) {
    //     // cerr << "[" << c.l << " " << c.r << "]" << endl;
    // }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;
    qj.push_back({0, INF});
    ma[INF + 1] = priority_queue<int, vector<int>, greater<int>>();
    while (q--) {
        string s;
        cin >> s;
        if (s == "new") {
            int p, L;
            cin >> p >> L;
            do_new(p, L);
        }
        else if (s == "send") {
            int p;
            cin >> p;
            do_send(p);
        }
        else {
            int p, i;
            cin >> p >> i;
            do_delete(p, i);
        }
    }

    return 0;
}
