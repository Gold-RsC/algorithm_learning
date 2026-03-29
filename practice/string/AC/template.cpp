#include <iostream>
#include <queue>
using namespace std;
struct Trie {
    int next[26];
    int fail;
    int exist;

} t[100005];
int cnt;
void insert(const char* s) {
    int u = 0;
    for (int i = 0; s[i]; ++i) {
        int c = s[i] - 'a';
        if (!t[u].next[c]) {
            t[u].next[c] = ++cnt;
        }
        u = t[u].next[c];
    }
    ++t[u].exist;
}
void build() {
    queue<int> q;
    for (int i = 0; i < 26; ++i) {
        if (t[0].next[i]) {
            q.push(t[0].next[i]);
        }
    }
    while (!q.empty()) {
        auto x = q.front();
        q.pop();
        for (int i = 0; i < 26; ++i) {
            if (t[x].next[i]) {
                t[t[x].next[i]].fail = t[t[x].fail].next[i];
                q.push(t[x].next[i]);
            }
            else {
                t[x].next[i] = t[t[x].fail].next[i];
            }
        }
    }
}
int query(const char* s) {
    int u = 0, res = 0;
    for (int i = 0; s[i]; ++i) {
        u = t[u].next[s[i] - 'a'];

        for (int j = u; j > 0 && t[j].exist != -1; j = t[j].fail;) {
            res += t[j].exist;
            t[j].exist = -1;
        }
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    return 0;
}
