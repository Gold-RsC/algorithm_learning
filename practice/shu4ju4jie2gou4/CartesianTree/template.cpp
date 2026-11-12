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
#include <limits>
#include <iterator>
#include <cmath>
#include <cstring>
#include <cstdint>
using namespace std;
#define int long long
const int N = 1e6 + 5;


/**
 * @brief 笛卡尔树
 * @note
 *   1. 笛卡尔树是一种二叉树，每个节点由(k,w)构成
 *   2. k满足BST的性质: 中序遍历即为k的顺序
 *      w满足堆的性质: 最值在根处
 *   3. 若k和w分别互不相同，则笛卡尔树唯一
 *   4. 一般地，k=idx，w=a[idx]
 */
int a[N];  // k=idx,w=a[idx]
int n;
struct Node {
    int left, right;
    int parent;
};
struct CartesianTree {
    vector<Node> node;
    int root;
    CartesianTree() {
        node.assign(n + 1, {0, 0, 0});
        root = 0;
    }
    int build() {  // 单调栈维护右子树
        vector<int> stk(n + 1, 0);
        int top = 0;
        for (int i = 1; i <= n; ++i) {
            int k = top;
            while (k && a[stk[k]] > a[i]) {
                --k;
            }
            if (k) {
                node[stk[k]].right = i;
                node[i].parent     = stk[k];
            }
            else {
                root = i;
            }
            if (k < top) {
                node[i].left            = stk[k + 1];
                node[stk[k + 1]].parent = i;
            }
            stk[++k] = i;
            top      = k;
        }
        return root;
    }
};


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);


    return 0;
}
