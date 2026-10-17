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
typedef long long ll;
#define int long long
const int N = 2e5 + 5;
struct OP {
    char op;
    int x;
};
struct Fact {
    double x;
    int i;
    bool operator<(const Fact& _) const {
        if (x != _.x) {
            return x < _.x;
        }
        return i < _.i;
    }
};
void solve() {

    int n;
    cin >> n;
    vector<OP> a(n, {0, n});

    int last_wi = -1;
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        a[i].op = c;
        if (c == 'F') {

            int x;
            cin >> x;
            a[i].x = x;
        }
        else {

            if (last_wi != -1)
                a[last_wi].x = i;
            last_wi = i;
        }
    }
    int ans = 0;
    set<Fact> s, tmp;
    int next_wi = 0;
    int wi      = -1;
    int wcnt    = 0;
    int fcnt    = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i].op == 'F') {
            fcnt++;
            if (wi != -1) {
                auto c = Fact{(double)a[i].x * (next_wi - i) / (next_wi - wi), i};
                tmp.insert(c);
            }
            else {
                s.insert(Fact{(double)a[i].x, i});
            }
        }
        else {
            auto it = tmp.rbegin();
            auto jt = s.rbegin();
            for (int j = 1; j <= wcnt && j <= fcnt; ++j) {
                if (it == s.rend() || it == tmp.rend() || (jt != s.rend() && jt != tmp.rend() && *it < *jt)) {
                    swap(it, jt);
                }
                int add;
                if (it->i >= wi) {
                    add = a[it->i].x * (next_wi - it->i);
                }
                else {
                    add = a[it->i].x * (next_wi - wi);
                }
                // cerr << "! " << it->i << " " << add << endl;
                ans += add;

                ++it;
            }
            // cerr << "! end\n" << endl;
            for (auto c : tmp) {
                c.x = a[c.i].x;
                s.insert(c);
            }
            tmp.clear();

            ++wcnt;
            next_wi = a[i].x;
            wi      = i;
        }
    }
    if (a.back().op == 'F') {

        auto it = tmp.rbegin();
        auto jt = s.rbegin();
        for (int j = 1; j <= wcnt && j <= fcnt; ++j) {
            if (it == s.rend() || it == tmp.rend() || (jt != s.rend() && jt != tmp.rend() && *it < *jt)) {
                swap(it, jt);
            }
            int add;
            if (it->i >= wi) {
                add = a[it->i].x * (next_wi - it->i);
            }
            else {
                add = a[it->i].x * (next_wi - wi);
            }
            // cerr << "! " << it->i << " " << add << endl;
            ans += add;
            ++it;
        }
        // cerr << "! end\n" << endl;
    }
    else {
        auto it = tmp.rbegin();
        auto jt = s.rbegin();
        for (int j = 1; j <= wcnt && j <= fcnt; ++j) {
            if (it == s.rend() || it == tmp.rend() || (jt != s.rend() && jt != tmp.rend() && *it < *jt)) {
                swap(it, jt);
            }
            int add;
            add = a[it->i].x;
            // cerr << "! " << it->i << " " << add << endl;
            ans += add;
            ++it;
        }
    }
    cout << ans << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
