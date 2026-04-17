#include <iostream>
#include <climits>
using namespace std;
#define int uint64_t
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int _min = 0, _max = ULLONG_MAX;
    while (n--) {
        int a, b;
        cin >> a >> b;
        _min = max(a / (b + 1) + 1, _min);
        _max = min(a / b, _max);
    }
    cout << _min << " " << _max << endl;
    return 0;
}
