## STL 算法

### 通用

- 区间一律 **左闭右开** `[first, last)`。
- `<algorithm>`：排序、查找、修改、比较；`<numeric>`：数值。
- 要求有序的算法必须先按**同一比较器**排序。
- 输出迭代器不扩容 → 配 `back_inserter`。

### 排序

```cpp
template<class It> void sort(It first, It last);                     // O(n log n)，不稳定
template<class It, class Compare> void sort(It first, It last, Compare cmp);
template<class It> void stable_sort(It first, It last);              // 稳定
template<class It> void partial_sort(It first, It middle, It last);  // O(n log k)
template<class It> void nth_element(It first, It nth, It last);      // 平均 O(n)
template<class It> bool is_sorted(It first, It last);                // O(n)
template<class It> It is_sorted_until(It first, It last);
```

```cpp
vector<int> v = {3, 1, 2};
sort(v.begin(), v.end());                            // 升序
sort(v.begin(), v.end(), greater<int>());            // 降序

nth_element(v.begin(), v.begin() + 2, v.end());      // v[2] 是第 3 小
partial_sort(v.begin(), v.begin() + 3, v.end());     // 前 3 个有序

bool ok = is_sorted(v.begin(), v.end());
```

- 比较器必须是**严格弱序**（`a < a` 为假）。写成 `<=` 会让 `sort` 越界崩溃。

### 二分（要求有序）

```cpp
template<class It, class T> It lower_bound(It first, It last, const T& value);   // 第一个 >= value
template<class It, class T> It upper_bound(It first, It last, const T& value);   // 第一个 > value
template<class It, class T> pair<It,It> equal_range(It first, It last, const T& value);
template<class It, class T> bool binary_search(It first, It last, const T& value);
```

```cpp
vector<int> v = {1, 2, 2, 2, 5};

auto l = lower_bound(v.begin(), v.end(), 2);   // 第 1 个 2
auto u = upper_bound(v.begin(), v.end(), 2);   // 5 的位置
int  cnt = u - l;                              // 2 的个数 = 3

auto it = upper_bound(v.begin(), v.end(), 2) - 1;   // 最后一个 <= 2

// 找不到时返回 last
int idx = lower_bound(v.begin(), v.end(), 9) - v.begin();   // 5 == v.size()
```

- `equal_range` = `[lower_bound, upper_bound)`。
- `set` / `map` 有成员版本 O(log n)，别用通用版（O(n) 步进）。

### 查找

```cpp
template<class It, class T> It find(It first, It last, const T& value);          // O(n)
template<class It, class Pred> It find_if(It first, It last, Pred p);
template<class It, class T> size_type count(It first, It last, const T& value);  // O(n)
template<class It, class Pred> size_type count_if(It first, It last, Pred p);
template<class It> It min_element(It first, It last);                            // 返回迭代器
template<class It> It max_element(It first, It last);
template<class It> pair<It,It> minmax_element(It first, It last);
template<class It> It adjacent_find(It first, It last);                          // 首个相邻相等
template<class It> pair<It,It> mismatch(It first1, It last1, It first2);
```

```cpp
auto it = find(v.begin(), v.end(), 7);
if (it != v.end()) cout << *it;              // 必须先判存在

int mx = *max_element(v.begin(), v.end());   // 解引用才拿到值
```

- `min` / `max` 返回值；`min_element` / `max_element` 返回迭代器。

### 修改

```cpp
template<class In, class Out> Out copy(In first, In last, Out dst);
template<class In, class Out, class Pred> Out copy_if(In first, In last, Out dst, Pred p);
template<class In, class Out> Out move(In first, In last, Out dst);
template<class Out, class T> void fill(Out first, Out last, const T& value);
template<class Out, class Size, class T> Out fill_n(Out first, Size n, const T& value);
template<class In, class Out, class F> Out transform(In first, In last, Out dst, F f);
template<class It, class T> void replace(It first, It last, const T& old, const T& nw);
template<class It, class Pred> It remove_if(It first, It last, Pred p);   // **不真删**
template<class It> It unique(It first, It last);                          // 只去相邻
template<class It> void reverse(It first, It last);
template<class It> It rotate(It first, It middle, It last);
template<class It, class URBG> void shuffle(It first, It last, URBG&& g);
template<class F1, class F2> void iter_swap(F1 a, F2 b);                  // 交换指向的元素
```

```cpp
// erase-remove：remove 只把保留元素前移，返回新逻辑尾
v.erase(remove(v.begin(), v.end(), 7), v.end());
v.erase(remove_if(v.begin(), v.end(), [](int x) { return x > 10; }), v.end());

// unique 只去相邻重复，必须先排序
sort(v.begin(), v.end());
v.erase(unique(v.begin(), v.end()), v.end());

// 随机打乱
mt19937 rng(random_device{}());
shuffle(v.begin(), v.end(), rng);

// 把 [middle, last) 循环左移到前面
rotate(v.begin(), v.begin() + k, v.end());
```

- 目标必须已分配空间：`copy(a.begin(), a.end(), b.begin())` 要求 `b.size() >= a.size()`。
- 二元 `transform`：`transform(a.begin(), a.end(), b.begin(), out.begin(), plus<int>())`。

### 数值（`<numeric>`）

```cpp
template<class It, class T> T accumulate(It first, It last, T init);
template<class It, class Out> Out partial_sum(It first, It last, Out dst);
template<class It, class Out> Out adjacent_difference(It first, It last, Out dst);
template<class It, class T> T inner_product(It first1, It last1, It first2, T init);
template<class It, class T> void iota(It first, It last, T value);        // C++11
template<class M, class N> common_type_t<M,N> gcd(M m, N n);              // C++17
template<class M, class N> common_type_t<M,N> lcm(M m, N n);              // C++17
```

```cpp
// 初值类型决定返回类型：0 是 int，会溢出
// long long s = accumulate(v.begin(), v.end(), 0);
long long s = accumulate(v.begin(), v.end(), 0LL);

vector<int> pre(v.size());
partial_sum(v.begin(), v.end(), pre.begin());          // 前缀和

vector<int> idx(n);
iota(idx.begin(), idx.end(), 0);                       // 0,1,2,...
```

### 集合操作（要求有序）

```cpp
template<class I1, class I2, class Out> Out set_union(I1 f1, I1 l1, I2 f2, I2 l2, Out dst);
template<class I1, class I2, class Out> Out set_intersection(I1 f1, I1 l1, I2 f2, I2 l2, Out dst);
template<class I1, class I2, class Out> Out set_difference(I1 f1, I1 l1, I2 f2, I2 l2, Out dst);
template<class I1, class I2, class Out> Out set_symmetric_difference(I1 f1, I1 l1, I2 f2, I2 l2, Out dst);
template<class I1, class I2> bool includes(I1 f1, I1 l1, I2 f2, I2 l2);   // l2 是否被 l1 包含
template<class I1, class I2, class Out> Out merge(I1 f1, I1 l1, I2 f2, I2 l2, Out dst);
```

```cpp
vector<int> a = {1, 2, 3}, b = {2, 3, 4}, out;
set_intersection(a.begin(), a.end(), b.begin(), b.end(), back_inserter(out));  // 2 3
set_union(a.begin(), a.end(), b.begin(), b.end(), back_inserter(out));         // 1 2 3 4
```

### 堆

```cpp
template<class It> void make_heap(It first, It last);       // O(n)
template<class It> void push_heap(It first, It last);       // O(log n)
template<class It> void pop_heap(It first, It last);        // O(log n)
template<class It> void sort_heap(It first, It last);       // O(n log n)
template<class It> bool is_heap(It first, It last);
```

```cpp
vector<int> h = {3, 1, 2};
make_heap(h.begin(), h.end());          // 大根堆，h[0] 最大

h.push_back(5);                         // 先 push_back
push_heap(h.begin(), h.end());          // 再 push_heap

pop_heap(h.begin(), h.end());           // 堆顶挪到末尾
int top = h.back();
h.pop_back();                           // 再真正删掉

make_heap(h.begin(), h.end(), greater<int>());   // 小根堆
```

### 排列

```cpp
template<class It> bool next_permutation(It first, It last);
template<class It> bool prev_permutation(It first, It last);
```

```cpp
sort(v.begin(), v.end());               // 必须先排序
do {
    // 处理当前排列
} while (next_permutation(v.begin(), v.end()));
```

- 绕回第一个排列时返回 `false`。

### 判断 / 遍历

```cpp
template<class It, class Pred> bool all_of(It first, It last, Pred p);
template<class It, class Pred> bool any_of(It first, It last, Pred p);
template<class It, class Pred> bool none_of(It first, It last, Pred p);
template<class It, class F> F for_each(It first, It last, F f);
template<class T> const T& clamp(const T& v, const T& lo, const T& hi);   // C++17
```

```cpp
bool all = all_of(v.begin(), v.end(), [](int x) { return x > 0; });
int y = clamp(x, 0, 100);
```
