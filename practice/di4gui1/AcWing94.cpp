// 排列型枚举
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


int n;

int a[20];
bool chosen[20];

void w(int b) {
    if (b == n + 1) {
        for (int i = 1; i <= n; ++i) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    for (int i = 1; i <= n; ++i) {
        if (chosen[i]) {
            continue;
        }
        chosen[i] = true;
        a[b]      = i;
        w(b + 1);
        chosen[i] = false;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    cin >> n;

    // 法一
    // vector<int> a(n);
    // iota(a.begin(), a.end(), 1);
    // do {
    //     for (auto x : a) {
    //         cout << x << " ";
    //     }
    //     cout << endl;
    // } while (next_permutation(a.begin(), a.end()));

    // 法二: 实现一个next_permutation，但没必要

    // 法三: 递归
    w(1);


    return 0;
}
