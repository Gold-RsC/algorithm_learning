// 指数型枚举
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
bool a[20];
void w(int i) {
    if (i == n + 1) {
        for (int i = 1; i <= n; ++i) {
            if (a[i]) {
                cout << i << " ";
            }
        }
        cout << endl;
        return;
    }
    w(i + 1);
    a[i] = true;
    w(i + 1);
    a[i] = false;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    cin >> n;
    // 法一：天然适合二进制存储，故直接递推
    // int m = (1 << n);
    // for (int i = 0; i < m; ++i) {
    //     for (int j = 0; j < n; ++j) {
    //         if ((i >> j) & 1) {
    //             cout << j + 1 << " ";
    //         }
    //     }
    //     cout << endl;
    // }

    // 法二：递归
    w(1);

    return 0;
}
