## STL 迭代器

### 分类

| 类别                   | 能力                  | 典型                                |
| ---------------------- | --------------------- | ----------------------------------- |
| 输入 input             | 单向读，单遍          | `istream_iterator`                  |
| 输出 output            | 单向写，单遍          | `ostream_iterator`、`back_inserter` |
| 前向 forward           | 单向读写，多遍        | `forward_list`、`unordered_*`       |
| 双向 bidirectional     | 前后移动              | `list`、`set`、`map`                |
| 随机访问 random access | `+ - [] <`，O(1) 跳转 | `vector`、`deque`、`array`          |

- `std::sort` 要求随机访问 → `list` 只能用 `list::sort()`。
- `std::distance`：随机访问 O(1)，其余 O(n)。

### 获取

```cpp
iterator begin();
iterator end();                  // 尾后，**不能解引用**
const_iterator cbegin() const;   // C++11
const_iterator cend() const;
reverse_iterator rbegin();       // 指向最后一个元素
reverse_iterator rend();
```

```cpp
vector<int> v = {1, 2, 3};

auto it  = v.begin();
auto it2 = next(it, 2);          // it2 指向 v[2]，it 不变
advance(it, 2);                  // it 本身变成 v[2]

ptrdiff_t d = distance(v.begin(), v.end());    // 3

for (auto rit = v.rbegin(); rit != v.rend(); ++rit)
    cout << *rit;                // 3 2 1
```

- 空容器 `begin() == end()`。
- `rbegin().base() == end()`；`reverse_iterator(it + 1)` 指向 `*it`。

### 插入迭代器

```cpp
back_insert_iterator<Container>  back_inserter(Container& c);            // 尾部
front_insert_iterator<Container> front_inserter(Container& c);           // 头部，要求 push_front
insert_iterator<Container>       inserter(Container& c, Iterator it);    // 在 it 前
```

```cpp
vector<int> src = {1, 2, 3}, dst;

// 错：dst 没有空间，写入是未定义行为
// copy(src.begin(), src.end(), dst.begin());

copy(src.begin(), src.end(), back_inserter(dst));    // 对
```

### 流迭代器

```cpp
istream_iterator<int> in(cin), eof;
vector<int> v(in, eof);                      // 读入全部整数

ostream_iterator<int> out(cout, " ");
copy(v.begin(), v.end(), out);               // 空格分隔输出
```

### 自由函数

```cpp
template<class C> auto begin(C& c)  -> decltype(c.begin());   // C++11
template<class C> auto end(C& c)    -> decltype(c.end());
template<class T, size_t N> T* begin(T (&a)[N]);              // 支持 C 数组
template<class T, size_t N> T* end(T (&a)[N]);
template<class C> auto size(const C& c) -> decltype(c.size());        // C++17
template<class C> bool empty(const C& c);                            // C++17
template<class C> auto data(C& c) -> decltype(c.data());             // C++17
```

```cpp
int a[5] = {1, 2, 3, 4, 5};
sort(begin(a), end(a));        // C 数组也能用 std::begin / std::end

vector<int> v = {1, 2, 3};
auto n = size(v);              // 3，C++17
```

- 泛型代码里用 `std::begin(c)` 而不是 `c.begin()`，这样能同时支持容器和裸数组。

### 反向 / 移动迭代器

```cpp
reverse_iterator       make_reverse_iterator(It it);       // C++14
move_iterator<It>      make_move_iterator(It it);          // C++11
```

```cpp
// 反向遍历
for (auto it = make_reverse_iterator(v.end()); it != make_reverse_iterator(v.begin()); ++it)

// 移动而不是拷贝：元素被搬走，源区间之后不要再用
vector<string> dst(make_move_iterator(src.begin()), make_move_iterator(src.end()));
```

### 失效规则

| 容器                                    | 插入                                                 | 删除                               |
| --------------------------------------- | ---------------------------------------------------- | ---------------------------------- |
| `vector`                                | 扩容时全部失效；否则失效插入点及之后                 | 删除点及之后失效                   |
| `deque`                                 | 两端插入全部迭代器失效（引用仍有效）；中间插入全失效 | 两端删除只失效被删；中间删除全失效 |
| `list` / `forward_list`                 | 不失效                                               | 只失效被删元素                     |
| `set` / `map` / `multiset` / `multimap` | 不失效                                               | 只失效被删元素                     |
| `unordered_*`                           | rehash 时全部失效（引用/指针不失效）                 | 只失效被删元素                     |

```cpp
// 遍历中删除：用 erase 的返回值
for (auto it = v.begin(); it != v.end();) {
    if (*it == x) it = v.erase(it);
    else          ++it;
}

// 错：范围 for 里删除，迭代器失效
// for (int x : v) if (x == 0) v.erase(...);
```

- 失效后的迭代器不能再用，**哪怕只做比较**。

### 自定义迭代器

```cpp
struct Iter {
    using value_type        = int;
    using difference_type   = ptrdiff_t;
    using pointer           = int*;
    using reference         = int&;
    using iterator_category = random_access_iterator_tag;
    // 还需实现 * ++ -- + - [] == != 等
};
```

- `std::iterator_traits<It>` 可取上面几个 typedef。
