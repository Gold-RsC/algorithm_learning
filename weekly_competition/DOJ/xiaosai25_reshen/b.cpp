#include <iostream>
#include <iomanip>
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
#include <climits>
#include <bitset>
using namespace std;
int m_zheng[101];
int m_fan[256];
int rev(int x) {
    int r = 0;
    for (int i = 0; i < 8; ++i) {
        r |= ((x >> i) & 1) << (7 - i);
    }
    return r;
}
void init() {
    for (int i = 1, x = 0; i <= 100; ++i) {
        while (m_fan[x]) {
            ++x;
        }
        int r      = rev(x);
        m_zheng[i] = min(r, x);
        m_fan[r] = m_fan[x] = i;
    }
}
string tobit(int x) {
    string s;
    for (int i = 0; i < 8; ++i) {
        s += ((x >> (7 - i)) & 1) + '0';
    }
    return s;
}
int frombit(string s) {
    int x = 0;
    x     = bitset<8>(s).to_ullong();
    reverse(s.begin(), s.end());
    x = min<int>(bitset<8>(s).to_ullong(), x);
    return x;
}
void chuandi(int x) {
    cout << "! " << tobit(m_zheng[x]) << endl;
    cout.flush();
}
void first_() {
    bool f = 0;
    for (int i = 1; i <= 99; ++i) {
        cout << "? " << i << endl;
        cout.flush();
        cin >> f;
        if (f) {
            chuandi(i);
            return;
        }
    }
    chuandi(100);
    return;
}
void second_() {
    string s;
    cin >> s;
    cout << m_fan[frombit(s)] << endl;
    cout.flush();
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    // for (int i = 0; i < 256; ++i) {
    //     cout << tobit(i) << " " << m_fan[i] << endl;
    // }
    string s;
    cin >> s;
    if (s == "first") {
        int t;
        cin >> t;
        while (t--) {
            first_();
        }
    }
    else {
        int t;
        cin >> t;
        while (t--) {
            second_();
        }
    }
    return 0;
}
