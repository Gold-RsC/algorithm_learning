#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
struct dsu {
    vector<size_t> parent, size;
    dsu(size_t _size)
        : parent(_size),
          size(_size, 1) {
        iota(parent.begin(), parent.end(), 0);
    }
    // 普通查找
    // size_t find(size_t x) {
    //     return parent[x] == x ? x : find(parent[x]);
    // }
    // 压缩式查找
    size_t find(size_t x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }
    // 普通合并
    // void unite(size_t x, size_t y) {
    //     parent[find(x)] = find(y);
    // }
    // 启发式合并
    void unite(size_t x, size_t y) {
        x = find(x), y = find(y);
        if (x == y) {
            return;
        }
        if (size[x] < size[y]) {
            swap(x, y);
        }
        parent[y] = x;
        size[x] += size[y];
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    return 0;
}
