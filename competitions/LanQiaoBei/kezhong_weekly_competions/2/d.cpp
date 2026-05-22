#include <iostream>
#include <string>
using namespace std;
int r[26];
void print(char j) {
    for (int i = 0; i < r[j - 'a']; i++) {
        cout << j;
    }
    r[j - 'a'] = 0;
}
int main() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    for (int i = 0; i < m; ++i) {
        char a;
        cin >> a;
        ++r[a - 'a'];
    }

    char current_min_char = 'a' - 1;
    for (int i = 0; i < n; ++i) {
        if (s[i] > current_min_char) {
            for (char j = current_min_char + 1; j < s[i]; ++j) {
                print(j);
            }
            current_min_char = s[i] - 1;
        }
        cout << s[i];
    }
    for (char j = current_min_char + 1; j <= 'z'; ++j) {
        print(j);
    }
    return 0;
}
