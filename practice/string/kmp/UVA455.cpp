#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> get_kmp(const string& s) {
    vector<int> ret(s.size());
    ret[0] = 0;
    for (int i = 1; i < s.size(); ++i) {
        int j = ret[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = ret[j - 1];
        }
        if (s[i] == s[j]) {
            ++j;
        }
        ret[i] = j;
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    cout << get_kmp(s).back();


    return 0;
}
