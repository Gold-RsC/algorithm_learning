#include <iostream>
#include <algorithm>
using namespace std;
// n:宝石数
// m:体力值
int n, m;
const int N = 100005;

int a[N];

int tree_max[4 * N];
int tree_semax[4 * N];
struct Cursor {
    int left, right;
    int pos;
};

#define MID c.left + (c.right - c.left) / 2
pair<int, int> merge(pair<int, int> p1, pair<int, int> p2) {
    int s[4] = {p1.first, p1.second, p2.first, p2.second};
    sort(s, s + 4, [&](int i, int j) {
        if (a[i] != a[j]) {
            return a[i] > a[j];
        }
        return i < j;
    });
    pair<int, int> ans;
    ans.first = s[0];
    if (s[1] != -1 && s[1] != s[0]) {
        ans.second = s[1];
    }
    else if (s[2] != -1 && s[2] != s[1]) {
        ans.second = s[2];
    }
    else if (s[3] != -1 && s[3] != s[2]) {
        ans.second = s[3];
    }
    else {
        ans.second = -1;
    }
    return ans;
}
void build(Cursor c) {
    if (c.left == c.right) {
        tree_max[c.pos]   = c.left;
        tree_semax[c.pos] = -1;
        return;
    }
    int mid = MID;
    build({c.left, mid, c.pos * 2});
    build({mid + 1, c.right, c.pos * 2 + 1});
    auto p = merge({tree_max[c.pos * 2], tree_semax[c.pos * 2]}, {tree_max[c.pos * 2 + 1], tree_semax[c.pos * 2 + 1]});
    tree_max[c.pos]   = p.first;
    tree_semax[c.pos] = p.second;
}
pair<int, int> find(int find_left, int find_right, Cursor c) {
    if (find_left <= c.left && c.right <= find_right) {
        return {tree_max[c.pos], tree_semax[c.pos]};
    }
    int mid = MID;
    if (find_right <= mid) {
        return find(find_left, find_right, {c.left, mid, c.pos * 2});
    }
    if (find_left > mid) {
        return find(find_left, find_right, {mid + 1, c.right, c.pos * 2 + 1});
    }
    return merge({tree_max[c.pos * 2], tree_semax[c.pos * 2]}, {tree_max[c.pos * 2 + 1], tree_semax[c.pos * 2 + 1]});
}

int ans[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build({1, n, 1});
    ans[0] = -1;
    for (int j = 1; j <= n; ++j) {
        // 在j+1到n寻找下标i，使得所指向的a[i]最大且a[i]!=a[j]且体力不耗尽
        pair<int, int> d = find(j, min(j + m, n), {1, n, 1});

        if (d.first != -1) {
            if (ans[j - 1] != a[d.first]) {
                ans[j] = a[d.first];
                m -= d.first - j;
                pop(d.first);
            }
            else if (d.second != -1) {
                ans[j] = a[d.second];
                m -= d.second - j;
                pop(d.second);
            }
            else {
                ans[j] = -1;
            }
        }
        else {
            ans[j] = -1;
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << ' ';
    }


    return 0;
}
