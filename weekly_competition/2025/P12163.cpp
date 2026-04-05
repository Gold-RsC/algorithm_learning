#include <iostream>
#include <string>
using namespace std;
bool check(int i) {
    string a   = to_string(i);
    int req[3] = {1, 2, 1};
    for (auto x : a) {
        if (x == '0' && req[0]) {
            req[0]--;
        }
        else if (x == '2' && req[1]) {
            req[1]--;
        }
        else if (x == '5' && req[2]) {
            req[2]--;
        }
        if (!(req[0] || req[1] || req[2])) {
            cout << i << endl;
            return true;
        }
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int ans = 0;
    for (int i = 1000; i <= 20250412; ++i) {
        if (check(i)) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}
