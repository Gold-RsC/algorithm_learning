#include <iostream>
#include <iomanip>
#include <array>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <string>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <climits>
#include <cstring>
#include <cstdint>
using namespace std;
#define int long long
const int N = 1e5 + 5;

/**
 * @brief 普通莫队
 */
int n, m;  // n是点数，m是询问数
int block_size;

void init() {
    block_size = sqrt(n);  // 有时候n/sqrt(m)会更快
}
int block(int x) {
    return x / block_size;
}
struct Query {
    int l, r;
    int id;

    int len() const {
        return (r - l + 1);
    }

    // 奇偶化排序
    bool operator<(const Query& _) const {
        if (block(l) != block(_.l)) {
            return l < _.l;
        }
        return (block(l) & 1) ? r < _.r : r > _.r;
    }
} q[N];

int ans[N];

int c[N];  // 数据

void add(int x) {
}
void del(int x) {
}

void solve() {
    sort(q + 1, q + m + 1);

    int curL = 1, curR = 0;  // 左闭右闭
    for (int i = 1; i <= m; ++i) {
        // 注意add是先自增自减，del是后自增自减
        // 最好不要改变这里四个while的顺序
        // 可用的while顺序：先扩大后缩小（当然不只有这四种）
        while (curL > q[i].l)
            add(--curL);
        while (curR < q[i].r)
            add(++curR);
        while (curL < q[i].l)
            del(curL++);
        while (curR > q[i].r)
            del(curR--);

        ans[q[i].id] = ;
    }
}
/**
 * @brief 单点修改的莫队
 * @note 只需要增加一个维度——修改维度
 * @note operator<的处理为：再在后面加一个return t<_.t
 * @note 新加的两个while应放到其他四个while前面或后面
 */
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);


    return 0;
}
