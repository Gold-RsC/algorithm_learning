#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<string, int> m;
vector<int> v;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    v.resize(s.size());
    for (int i = 0; i < s.size(); ++i) {
        for (int j = i; j < s.size(); ++j) {
            string sub = s.substr(i, j - i + 1);
            ++m[sub];
        }
    }
    for (auto x : m) {
        ++v[x.second - 1];
    }
    for (auto x : v) {
        cout << x << "\n";
    }
    return 0;
}
