#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
vector<int> p[10];
bool m[5005][5005];
string s;
int ans;

void w(int i, int d) {
    if (m[i][i + d]) {
        ++ans;
        return;
    }
    if (s[i] > s[i + d]) {
        m[i][i + d] = true;
        ++ans;
    }
    else if (s[i] == s[i + d]) {
        if (d <= 2) {
            m[i][i + d] = false;
        }
        else {
            w(i + 1, d - 2);
            m[i][i + d] = m[i + 1][i + d - 1];
        }
    }
}
int main() {
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        p[s[i] - '0'].push_back(i);
    }
    for (int d = 1; d <= s.size() - 1; ++d) {
        for (int i = 0; i + d < s.size(); ++i) {
            w(i, d);
        }
    }
    cout << ans << endl;
    return 0;
}
