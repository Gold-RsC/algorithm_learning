#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int N = 1e6 + 10;
struct trie {
    int next[N][26];
    int cnt;
    bool exist[N];
    bool read[N];
    void insert(const char* s, int len) {
        int ptr = 0;
        for (int i = 0; i < len; ++i) {
            int c = s[i] - 'a';
            if (!next[ptr][c]) {
                ++cnt;
                next[ptr][c] = cnt;
            }
            ptr = next[ptr][c];
        }
        exist[ptr] = true;
    }
    int find(const char* s, int len) {
        int ptr = 0;
        for (int i = 0; i < len; ++i) {
            int c = s[i] - 'a';
            if (!next[ptr][c]) {
                return 0;
            }
            ptr = next[ptr][c];
        }
        if (!exist[ptr]) {
            return 0;
        }
        if (read[ptr]) {
            return 1;
        }
        read[ptr] = true;
        return 2;
    }
} t;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        t.insert(s.c_str(), s.size());
    }
    int m;
    cin >> m;
    while (m--) {
        string s;
        cin >> s;
        switch (t.find(s.c_str(), s.size())) {
            case 0: {
                cout << "WRONG\n";
                break;
            }
            case 1: {
                cout << "REPEAT\n";
                break;
            }
            case 2: {
                cout << "OK\n";
                break;
            }
            default: {
                cout << "CAONIMA\n";
            }
        }
    }

    return 0;
}
