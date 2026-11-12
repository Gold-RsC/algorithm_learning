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
#include <limits>
#include <cmath>
#include <cstring>
#include <cstdint>
using namespace std;
#define int long long


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 2; i <= 600; i++) {
        bool f = true;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                f = false;
                break;
            }
        }
        if (!f)
            continue;
        for (int k = 0; k <= 60; k++) {
            if (((k * i + 1) ^ (i - 1)) >= (((k + 2) * i + 1) ^ (i - 1))) {
                cout << i << ' ' << k << ' ' << ((k * i + 1) ^ (i - 1)) << ' ' << (((k + 2) * i + 1) ^ (i - 1)) << '\n';
            }
        }
    }
    return 0;
}
