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
using namespace std;
#define int uint64_t


const int N = 3402 + 5;
const int W = 12880 + 5;
struct item {
    int w, v;
};
item a[N];

int dpwq[W];
void beibaowq() {
    int n, w;
    cin >> n >> w;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].w >> a[i].v;
    }


    for (int i = 1; i <= n; ++i) {
        for (int j = a[i].w; j <= w; ++j) {
            dpwq[j] =
                max(dpwq[j], dpwq[j - a[i].w] + a[i].v);
        }
    }
    cout << dpwq[w];
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    beibaowq();
    return 0;
}
