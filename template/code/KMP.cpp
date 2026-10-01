#include <iostream>
#include <string>
#include <vector>
using namespace std;
string s;
string k;
vector<int> kmp;
void set_kmp(void) {
    kmp[0] = 0;
    for (int i = 1; i <= k.size(); ++i) {
        int j = kmp[i - 1];
        while (j > 0 && k[i] != k[j]) {
            j = kmp[j - 1];
        }
        if (k[i] == k[j]) {
            ++j;
        }
        kmp[i] = j;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s >> k;
    kmp.resize(k.size());
    set_kmp();

    for (int i = 0, j = 0; i < s.size(); ++i) {

        while (j > 0 && s[i] != k[j]) {
            j = kmp[j - 1];
        }
        if (s[i] == k[j]) {
            ++j;
        }
        if (j == k.size()) {
            cout << i - k.size() + 2 << endl;
            j = kmp[j - 1];
        }
    }
    for (int i = 0; i < kmp.size(); ++i) {
        cout << kmp[i] << " ";
    }


    return 0;
}
