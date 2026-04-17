#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define int uint64_t
int get_len(int n) {
    int len = 0;
    while (n) {
        n /= 10;
        ++len;
    }
    return len;
}

int pow5(int a) {
    if (a == 0) {
        return 0;
    }
    if (a == 1) {
        return 5;
    }
    return pow5(a / 2) * pow5(a - a / 2);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    n += 10;
    int len = 2;
    for (int a = 10; a < n && a * 5 >= n; a *= 5, ++len) {
    }
    pow5(len - 1);

    return 0;
}
