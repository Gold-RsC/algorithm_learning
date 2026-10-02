struct DSU {
    vector<size_t> parent, size;
    DSU(size_t n)
        : parent(n),
          size(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    size_t find_root(size_t x) {
        return parent[x] == x ? x : parent[x] = find_root(parent[x]);
    }
    void unite(size_t x, size_t y) {
        x = find_root(x), y = find_root(y);
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
