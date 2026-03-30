#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int N = 150 * 70 + 5;
struct Trie {
    int son[26];
    int fail;
    int exist;
} t[N];
vector<string> pattern;
int endnode[N];

// 节点编号
int cnt;

// trie普通构建
void insert(const char* s, int idx) {
    int u = 0;
    for (int i = 0; s[i]; ++i) {
        int c = s[i] - 'a';
        if (!t[u].son[c]) {
            t[u].son[c] = ++cnt;
        }
        u = t[u].son[c];
    }
    endnode[idx] = u;
}

// AC自动机构建
void build() {
    queue<int> q;
    for (int c = 0; c < 26; ++c) {
        if (t[0].son[c]) {
            q.push(t[0].son[c]);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int c = 0; c < 26; ++c) {
            if (t[u].son[c]) {
                t[t[u].son[c]].fail = t[t[u].fail].son[c];
                q.push(t[u].son[c]);
            }
            else {
                t[u].son[c] = t[t[u].fail].son[c];
            }
        }
    }
}

// 匹配
void query(const char* s) {
    int u = 0;

    for (int i = 0; s[i]; ++i) {
        int c = s[i] - 'a';

        u = t[u].son[c];
        for (int j = u; j; j = t[j].fail) {
            t[j].exist++;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while (1) {
        int n;
        cin >> n;
        if (n) {
            for (int i = 0; i <= cnt; ++i) {
                t[i] = {};
            }
            cnt = 0;
        }
        else {
            break;
        }
        pattern.resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> pattern[i];
            insert(pattern[i].c_str(), i);
        }
        build();

        string s;
        cin >> s;
        query(s.c_str());

        int max_cnt = 0;
        for (int i = 0; i < n; ++i) {

            max_cnt = max(max_cnt, t[endnode[i]].exist);
        }
        cout << max_cnt << '\n';
        for (int i = 0; i < n; ++i) {
            if (max_cnt == t[endnode[i]].exist) {
                cout << pattern[i] << '\n';
            }
        }
    }
    return 0;
}
