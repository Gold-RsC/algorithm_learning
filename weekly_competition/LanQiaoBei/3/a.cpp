#include <iostream>
#include <cmath>
using namespace std;
#define int uint64_t
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a, b, n;
    cin >> a >> b >> n;
    int w    = a * 5 + b * 2;
    int ans  = n / w * 7;
    int work = n / w * w;
    for (int i = 1; i <= 7; ++i) {
        if (i <= 5) {
            work += a;
        }
        else {
            work += b;
        }
        ++ans;
        if (work >= n) {
            break;
        }
    }
    cout << ans;

    return 0;
}
