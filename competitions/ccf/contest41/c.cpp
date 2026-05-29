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
bool operator==(const QuJian& a, const QuJian& b) {
    return a.l == b.l && a.r == b.r;
}
vector<QuJian> qj;
unordered_map<int, priority_queue<int, vector<int>, greater<int>>> ma;
vector<int> len_list;
void ma_sayerr() {
    for (auto& [len, pq] : ma) {
        if (pq.empty()) {
            continue;
        }

        stack<int> a;
        cerr << len << " :[";
        while (!pq.empty()) {
            cerr << pq.top() << " ";
            a.push(pq.top());
            pq.pop();
        }
        cerr << "]" << endl;
        while (!a.empty()) {
            pq.push(a.top());
            a.pop();
        }
    }
}
void ma_pop(int len, int x) {
    if (!ma.count(len) || ma[len].empty()) {
        return;
    }

    stack<int> a;
    while (!ma[len].empty() && ma[len].top() != x) {
        a.push(ma[len].top());
        ma[len].pop();
    }
    if (!ma[len].empty()) {
        ma[len].pop();
    }
    while (!a.empty()) {
        ma[len].push(a.top());
        a.pop();
    }
}
void lenlist_erase(int len) {
    if (!ma[len].empty()) {
        return;
    }
    auto it = lower_bound(len_list.begin(), len_list.end(), len);
    if (*it == len) {
        len_list.erase(it);
    }
}
void lenlist_insert(int len) {
    auto it = lower_bound(len_list.begin(), len_list.end(), len);
    if (*it == len) {
        return;
    }
    len_list.insert(it, len);
}
void do_new(int p, int L) {
    int a = 0;


    for (auto it = lower_bound(len_list.begin(), len_list.end(), L); it != len_list.end(); ++it) {
        auto len = *it;
        auto& pq = ma[len];
        if (pq.empty()) {
            continue;
        }
        a       = pq.top();
        auto& q = *lower_bound(qj.begin(), qj.end(), QuJian{a, 114514});
        q.l     = a + L;
        pq.pop();
        ma[len - L].push(q.l);
        if (pq.empty()) {
            len_list.erase(it);
        }
        lenlist_insert(len - L);


        break;
        // cerr << "$ pop " << len << " " << a << endl;
        // cerr << "$ push " << len - L << " " << q.l << endl;
    }

    jc[p].jk.push_back({a, L, -1});
    cout << a << endl;
    // for (auto c : qj) {
    //     cerr << "[" << c.l << " " << c.r << "]" << endl;
    // }
    // ma_sayerr();
}
void do_send(int p) {
    int ans = 0;
    for (auto& jk : jc[p].jk) {
        jk.ptr = (jk.ptr + 1) % jk.L;
        ans += jk.ptr + jk.a;
    }
    cout << ans << endl;
}

void do_delete(int p, int i) {
    auto& jk = jc[p].jk[i];

    auto it = lower_bound(qj.begin(), qj.end(), QuJian{jk.a, 114514});
    // cerr << it - qj.begin();
    if (it->l == jk.a + jk.L) {
        if (it == qj.begin()) {
            ma[it->r - it->l + 1].pop();
            lenlist_erase(it->r - it->l + 1);
            it->l = jk.a;
            ma[it->r - it->l + 1].push(it->l);
            lenlist_insert(it->r - it->l + 1);
        }
        else {
            if ((it - 1)->r + 1 == jk.a) {
                ma_pop((it - 1)->r - (it - 1)->l + 1, (it - 1)->l);
                lenlist_erase((it - 1)->r - (it - 1)->l + 1);
                ma_pop(it->r - it->l + 1, it->l);
                lenlist_erase(it->r - it->l + 1);
                ma[it->r - (it - 1)->l + 1].push((it - 1)->l);
                lenlist_insert(it->r - (it - 1)->l + 1);
                (it - 1)->r = it->r;
                qj.erase(it);
            }
            else {
                ma_pop(it->r - it->l + 1, it->l);
                lenlist_erase(it->r - it->l + 1);
                it->l = jk.a;
                ma[it->r - it->l + 1].push(it->l);
                lenlist_insert(it->r - it->l + 1);
            }
        }
    }
    else {
        if (it == qj.begin()) {
            qj.insert(it, {jk.a, jk.a + jk.L - 1});
            ma[jk.L].push(jk.a);
            lenlist_insert(jk.L);
        }
        else {
            if ((it - 1)->r + 1 == jk.a) {
                ma_pop((it - 1)->r - (it - 1)->l + 1, (it - 1)->l);
                lenlist_erase((it - 1)->r - (it - 1)->l + 1);
                (it - 1)->r = jk.a + jk.L - 1;
                ma[(it - 1)->r - (it - 1)->l + 1].push((it - 1)->l);
                lenlist_insert((it - 1)->r - (it - 1)->l + 1);
            }
            else {
                qj.insert(it, {jk.a, jk.a + jk.L - 1});
                ma[jk.L].push(jk.a);
                lenlist_insert(jk.L);
            }
        }
    }
    jc[p].jk.erase(jc[p].jk.begin() + i);


    // for (auto c : qj) {
    //     cerr << "[" << c.l << " " << c.r << "]" << endl;
    // }
    // ma_sayerr();
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;
    qj.push_back({0, INF});
    len_list.push_back(INF + 1);
    ma[INF + 1].push(0);
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
            do_delete(p, i - 1);
        }
    }

    return 0;
}
