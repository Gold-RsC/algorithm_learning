#include <iostream>
#include <queue>
using namespace std;

const int N = 1e6 + 5;
struct Trie {
    int son[26];
    int fail;
    int exist;

} t[N];

// 节点编号
int cnt;

// trie普通构建
void insert(const char* s) {
    int u = 0;
    for (int i = 0; s[i]; ++i) {
        int c = s[i] - 'a';
        if (!t[u].son[c]) {
            t[u].son[c] = ++cnt;
        }
        u = t[u].son[c];
    }
    ++t[u].exist;
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
int query(const char* s) {
    int u   = 0;
    int ret = 0;  // 匹配数
    for (int i = 0; s[i]; ++i) {
        int c = s[i] - 'a';

        u = t[u].son[c];
        for (int j = u; j && t[j].exist != -1; j = t[j].fail) {
            ret += t[j].exist;
            t[j].exist = -1;  // exist=-1指已经询问过了，但这种方法只能询问一次，若想多次询问则需要构建visited状态
        }
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        insert(s.c_str());
    }
    build();

    string s;
    cin >> s;
    cout << query(s.c_str());
    return 0;
}
