#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct trie {
    int next[100000][26];
    int cnt;
    bool exist[100000];

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
    bool find(const char* s, int len) {
        int ptr = 0;
        for (int i = 0; i < len; ++i) {
            int c = s[i] - 'a';
            if (!next[ptr][c]) {
                return false;
            }
            ptr = next[ptr][c];
        }
        return exist[ptr];
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    return 0;
}
