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

const int N = 2e5 + 5;
int n;
int a[N];
unordered_map<int, int> ma;
int m;
struct V {
    int b, c, id;
};
V v[N];
bool cmp(const V& x, const V& y) {
    if (ma[x.b] != ma[y.b]) {
        return ma[x.b] > ma[y.b];
    }
    if (ma[x.c] != ma[y.c]) {
        return ma[x.c] > ma[y.c];
    }
    return x.id < y.id;
}

vector<int> discrete(vector<int> a) {
    if (a.empty()) {
        return {};
    }
    sort(a.begin(), a.end());
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
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        ma[a[i]]++;
    }


    cin >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> v[i].b;
    }
    for (int i = 1; i <= m; ++i) {
        cin >> v[i].c;
    }
    for (int i = 1; i <= m; ++i) {
        v[i].id = i;
    }
    sort(v + 1, v + 1 + m, cmp);
    cout << v[1].id;
    return 0;
}
