#include <iostream>
#include <map>
using namespace std;

struct state {
    int len;
    int link;
    map<char, int> next;
};
const int N = 1000000;
state st[N * 2];
int sz, last;
void sam_init() {
    st[0].len  = 0;
    st[0].link = -1;
    sz++;
    last = 0;
}
void sam_extend(char c) {
    int cur     = sz++;
    st[cur].len = st[last].len + 1;
    int p       = last;
    while (p != -1 && !st[p].next.count(c)) {
        st[p].next[c] = cur;
        p             = st[p].link;
    }
    if (p == -1) {
        st[cur].link = 0;
    }
    else {
        int q = st[p].next[c];
        if (st[p].len + 1 == st[q].len) {
            st[cur].link = q;
        }
        else {
            int clone      = sz++;
            st[clone].len  = st[p].len + 1;
            st[clone].next = st[q].next;
            st[clone].link = st[q].link;
            while (p != -1 && st[p].next[c] == q) {
                st[p].next[c] = clone;
                p             = st[p].link;
            }
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}
void sam_build(string s) {
    sam_init();
    for (auto x : s) {
        sam_extend(x);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    return 0;
}
