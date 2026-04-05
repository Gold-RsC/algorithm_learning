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
#define int int64_t
int p;

int qpow(int a, int b) {
    int ret = 1;
    while (b) {
        if (b & 1) {
            ret = ret * a % p;
        }
        a = a * a % p;
        b >>= 1;
    }
    return ret;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a, b;
    cin >> a >> b >> p;
    cout << a << "^" << b << " mod " << p << "="
         << qpow(a, b);

    return 0;
}
