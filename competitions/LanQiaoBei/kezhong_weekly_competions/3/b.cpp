#include <iostream>
#include <string>
using namespace std;
bool check(string a) {
    if (a.size() <= 16 && a.size() >= 8) {
        bool f1 = false, f2 = false;
        for (auto x : a) {
            if (x <= '9' && x >= '0') {
                f1 = true;
            }
            else if (x <= 'z' && x >= 'a') {
            }
            else if (x <= 'Z' && x >= 'A') {
            }
            else {
                f2 = true;
            }
        }
        if (f1 && f2) {
            return true;
        }
    }
    return false;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string a = "kfdhtshmrw4nxg#f44ehlbn33ccto#mwfn2waebry#3qd1ubwyhcyuavuajb#vyecsycuzsmwp31ipzah#catatja3kaqbcss2th";

    int ans = 0;
    for (int i = 0; i < a.size(); ++i) {
        for (int len = 8; len <= 16; ++len) {

            if (check(a.substr(i, min<int>(len, a.size() - i)))) {
                ans++;
                cerr << i << " " << len << endl;
            }
        }
    }
    cout << ans;

    return 0;
}
