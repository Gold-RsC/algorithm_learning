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
#include <cmath>
#include <climits>
#include <cstring>
#include <cstdint>
using namespace std;
#define int long long

map<string, char> m;

int n;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; ++i) {
        string s;
        int c;
        cin >> s >> c;
        m.insert(pair<string, char>(s, c));
    }

    string s;
    cin >> s;
    string tmp;
    for (char c : s) {
        tmp.push_back(c);
        auto it = m.find(tmp);
        if (it != m.end()) {
            cout << it->second;
            tmp.clear();
        }
    }

    return 0;
}
