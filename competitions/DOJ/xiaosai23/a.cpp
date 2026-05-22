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

int n;
unordered_map<string, int> m{
    {"Au", 3},
    {"Ag", 1},
    {"Cu", 0},
    {"Fe", 0},
};

struct Q {
    int fanhuan;
    int w;
    int fanhuan_baoxiao;
};
int sum_w;
int e;
const int N = 1010;
unordered_map<string, Q> q;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    string tmp;

    for (int i = 0; i < n; ++i) {
        string name;
        int cost;
        int dw;
        cin >> name;
        cin >> tmp;
        cin >> cost;
        cin >> tmp;
        dw = m[tmp];

        q[name].w += dw;
        if (tmp == "Fe") {
            q[name].fanhuan += cost * 2 / 5;
            e += cost - (cost * 2 / 5);
        }
        else {
            q[name].fanhuan += cost;
        }
        sum_w += dw;
    }

    e = max(1, e) - 1;
    for (auto& x : q) {
        // cout << "@ " << x.first << " " <<
        // x.second.fanhuan
        //      << endl;
        x.second.fanhuan_baoxiao =
            x.second.fanhuan + e * x.second.w / sum_w;
    }

    map<string, Q> v;
    for (auto& x : q) {
        v.insert(x);
    }
    for (auto& x : v) {
        cout << x.first << " " << x.second.fanhuan_baoxiao
             << endl;
    }
    return 0;
}
