## STL 容器

### 速查

| 容器                                        | 底层                   | 随机访问   | 插入 / 删除              | 迭代器   |
| ------------------------------------------- | ---------------------- | ---------- | ------------------------ | -------- |
| `vector`                                    | 连续数组               | O(1)       | 末尾均摊 O(1)，中间 O(n) | 随机访问 |
| `deque`                                     | 分段连续               | O(1)       | 两端 O(1)，中间 O(n)     | 随机访问 |
| `list`                                      | 双向链表               | 不支持     | O(1)\*                   | 双向     |
| `forward_list`                              | 单向链表               | 不支持     | O(1)\*                   | 前向     |
| `array`                                     | 定长数组               | O(1)       | 不支持                   | 随机访问 |
| `string`                                    | 连续字符数组           | O(1)       | 末尾均摊 O(1)，中间 O(n) | 随机访问 |
| `set` / `map`                               | 红黑树                 | 不支持     | O(log n)                 | 双向     |
| `multiset` / `multimap`                     | 红黑树                 | 不支持     | O(log n)                 | 双向     |
| `unordered_set` / `unordered_map`           | 哈希表                 | 不支持     | 平均 O(1)，最坏 O(n)     | 前向     |
| `unordered_multiset` / `unordered_multimap` | 哈希表                 | 不支持     | 平均 O(1)，最坏 O(n)     | 前向     |
| `stack` / `queue`                           | 适配器（默认 `deque`） | 不支持     | O(1)                     | 无       |
| `priority_queue`                            | 堆                     | 仅 `top()` | O(log n)                 | 无       |
| `bitset`                                    | 定长位集               | 取位 O(1)  | 不支持                   | 无       |
\* 已持有迭代器；找位置仍是 O(n)。

### 通用

- 顺序容器和关联容器都有 `size()`、`empty()`、`clear()`、`swap()`；`stack` / `queue` / `priority_queue` **没有** `clear()`。
- `size()` 返回 `size_t`（无符号）。空容器时 `s.size() - 1` 回绕成极大值。
- `at()` 越界抛 `std::out_of_range`；`operator[]` **不检查**。
- `emplace` / `emplace_back` / `emplace_hint` 原地构造，省一次拷贝或移动。
- `assign(n, val)` / `assign(first, last)`：重置为 n 个 val 或一段区间（`vector` / `deque` / `list` / `string`）。
- `clear()` 是 O(n)（要析构元素）；`vector` 想连容量一起释放用 `shrink_to_fit()`。

### vector

```cpp
size_type size() const;                              // O(1)
size_type capacity() const;                          // O(1)
bool empty() const;                                  // O(1)
reference operator[](size_type i);                   // O(1)，不检查越界
reference at(size_type i);                           // O(1)，越界抛 out_of_range
reference front();                                   // O(1)，空容器未定义
reference back();                                    // O(1)
T* data();                                           // O(1)，C++11
void push_back(const T& x);                          // 均摊 O(1)
void pop_back();                                     // O(1)，空容器未定义
iterator insert(const_iterator pos, const T& x);     // O(n)，返回新元素位置
iterator erase(const_iterator pos);                  // O(n)，返回下一个
iterator erase(const_iterator first, const_iterator last);
void clear();                                        // O(n)
void reserve(size_type n);                           // 只改 capacity，不改 size
void resize(size_type n);                            // 改 size，多出的值初始化
void assign(size_type n, const T& value);            // 重置为 n 个 value
void assign(InputIt first, InputIt last);            // 重置为一段区间
void shrink_to_fit();                                // 释放多余 capacity
void swap(vector& other);                            // O(1)
```

```cpp
vector<int> v = {1, 2, 3};
v.reserve(100);            // 预留，避免反复扩容

// 遍历中删除：erase 返回下一个迭代器
for (auto it = v.begin(); it != v.end();) {
    if (*it % 2 == 0) it = v.erase(it);
    else              ++it;
}
```

- **扩容时迭代器、指针、引用全部失效**；未扩容的 `push_back` 只失效 `end()`。
- **`vector<bool>` 是特化**：按位存，`operator[]` 返回代理对象。

```cpp
vector<bool> vb(10, false);
bool x = vb[0];    // 读可以
// bool& r = vb[0];  错：不能绑定
// &vb[0]            错：不能取地址
```

### deque

```cpp
void push_front(const T& x);   // O(1)
void push_back(const T& x);    // O(1)
void pop_front();              // O(1)
void pop_back();               // O(1)
reference front();             // O(1)
reference back();              // O(1)
reference operator[](size_type i);   // O(1)，常数比 vector 大
iterator insert(const_iterator pos, const T& x);   // O(n)
iterator erase(const_iterator pos);                // O(n)
```

- 内存**不连续**，`v.data()` 不存在，不能传给 C 接口。
- 两端插入使**所有迭代器**失效（元素引用仍有效）；中间插入/删除使迭代器和引用全失效。

### list / forward_list

```cpp
// list
void push_front(const T& x);  void push_back(const T& x);   // O(1)
void splice(const_iterator pos, list& other);               // O(1)，直接摘链
void merge(list& other);                                    // O(n)，要求两表有序
void sort();                                                // O(n log n)，成员函数
void unique();                                              // O(n)，去相邻重复
void remove(const T& value);                                // O(n)
void reverse();                                             // O(n)

// forward_list（没有 size()、没有 push_back）
iterator before_begin();                                    // 头节点之前
iterator insert_after(const_iterator pos, const T& x);      // O(1)
iterator erase_after(const_iterator pos);                   // O(1)
```

```cpp
list<int> a = {3, 1, 2};
a.sort();                       // 不能用 std::sort(a.begin(), a.end())

forward_list<int> f = {1, 2, 3};
f.insert_after(f.before_begin(), 0);   // 头插
```

- 插入不失效；删除只失效被删元素。
- 每元素额外存指针，缓存不友好，小规模常不如 `vector`。

### array

```cpp
size_type size() const;              // 常量，编译期可知
reference at(size_type i);           // 越界抛 out_of_range
reference operator[](size_type i);   // 不检查
reference front();  reference back();
T* data();                           // 裸指针
void fill(const T& value);           // 全部赋值
```

```cpp
array<int, 3> a{1, 2, 3};
sort(a.begin(), a.end());            // 可直接传算法
```

- 栈上分配，无动态分配；可整体比较和拷贝。

### string

```cpp
size_type size() const;  size_type length() const;   // O(1)，两者等价
bool empty() const;                                  // O(1)
size_type capacity() const;
void reserve(size_type n);                           // 预留，避免反复扩容
void clear();                                        // O(n)

// 查找：找不到返回 string::npos
size_type find(const string& s, size_type pos = 0) const;
size_type find(char c, size_type pos = 0) const;
size_type rfind(const string& s, size_type pos = npos) const;

string substr(size_type pos = 0, size_type len = npos) const;   // O(len)
int compare(const string& s) const;                             // <0 / 0 / >0

string& append(const string& s);
string& insert(size_type pos, const string& s);
string& erase(size_type pos = 0, size_type len = npos);
string& replace(size_type pos, size_type len, const string& s);
void push_back(char c);                              // C++11
void pop_back();                                     // C++11

const char* c_str() const;                           // 末尾带 '\0'
const char* data() const;
```

```cpp
string s = "hello world";

size_t p = s.find("world");            // 6
if (p != string::npos) {               // 必须判 npos
    string t = s.substr(p, 5);         // "world"
}

s.replace(0, 5, "hi");                 // "hi world"
s.erase(2, 1);                         // 删 1 个字符
s += "!";                              // 追加
s.push_back('?');                      // 追加单字符

// 数值 <-> 字符串
int       a = stoi("42");              // 失败抛 invalid_argument / out_of_range
long long b = stoll("42");
double    c = stod("3.14");
string    d = to_string(123);          // "123"

// 读一整行（含空格）
string line;
getline(cin, line);
// cin >> x 之后紧跟 getline 会读到空行，先 cin.ignore()
```

- **`size()` 返回 `size_t`（无符号）**：空串时 `s.size() - 1` 回绕成极大值。

```cpp
for (int i = 0; i < s.size(); ++i)      // int 与无符号比较，有符号警告
for (size_t i = 0; i < s.size(); ++i)   // 对
```

- `find` 找不到返回 `string::npos`（`size_t(-1)`），**不能用 `< 0` 判断**。
- `substr(pos, len)`：`len` 超出范围自动截到末尾。
- `c_str()` 指向内部缓冲区，**任何修改或析构后失效**。
- `s = s + a + b` 会多次分配；循环拼接用 `s += x`，或先 `reserve`。
- C++17 可用 `string_view` 做只读视图，避免拷贝。

### set / multiset

```cpp
pair<iterator, bool> insert(const value_type& x);   // O(log n)，bool = 是否插入成功
size_type erase(const key_type& k);                 // O(log n)，返回删除个数
iterator erase(iterator pos);                       // O(1) 均摊
iterator find(const key_type& k);                   // O(log n)，找不到返回 end()
size_type count(const key_type& k);                 // O(log n)，set 只有 0 / 1
iterator lower_bound(const key_type& k);            // O(log n)，第一个 >= k
iterator upper_bound(const key_type& k);            // O(log n)，第一个 > k
pair<iterator, iterator> equal_range(const key_type& k);   // [lower, upper)
node_type extract(const key_type& k);               // C++17，取出节点后可改 key
```

```cpp
set<int> s = {3, 1, 2};
auto [it, ok] = s.insert(4);       // 有序：{1,2,3,4}

// 元素是 const：不能改值，只能删了重插
// *s.begin() = 5;   错

// 用成员版本，不要用 std::lower_bound（那是 O(n) 步进）
auto p = s.lower_bound(2);
```

- `multiset` 的 `insert` 返回 `iterator`（没有 bool）。

### map / multimap

```cpp
T& operator[](const key_type& k);                   // **不存在就插入 T()**
T& at(const key_type& k);                           // 不存在抛 out_of_range
pair<iterator, bool> insert(const value_type& kv);  // 不覆盖已存在的键
template<class... A> pair<iterator,bool> emplace(A&&... args);
template<class... A> pair<iterator,bool> try_emplace(const key_type& k, A&&... args);  // C++17
template<class M> pair<iterator,bool> insert_or_assign(const key_type& k, M&& obj);    // C++17
iterator find(const key_type& k);                   // 不存在返回 end()
size_type erase(const key_type& k);
iterator lower_bound(const key_type& k);
```

```cpp
map<string, int> m;
m["a"] = 1;                 // 插入 {"a", 1}
m["b"];                     // 插入 {"b", 0}！只读请用 find/at

if (auto it = m.find("a"); it != m.end()) {
    cout << it->second;
}

m.insert({"a", 99});        // 不覆盖，a 仍是 1
m.insert_or_assign("a", 99);// 覆盖
```

- 元素类型 `pair<const Key, T>`，**key 不可改**。

### unordered_set / unordered_map

```cpp
size_type bucket_count() const;
float load_factor() const;                  // size / bucket_count
float max_load_factor() const;
void max_load_factor(float z);
void rehash(size_type n);                   // 强制桶数
void reserve(size_type n);                  // 预留空间，避免 rehash
```

```cpp
unordered_map<string, int> um;
um.reserve(1000);            // 提前避免 rehash

// 自定义类型作 key：特化 std::hash + 提供 operator==
struct P { int x, y; bool operator==(const P& o) const { return x == o.x && y == o.y; } };
namespace std {
template <> struct hash<P> {
    size_t operator()(const P& p) const {
        return hash<int>{}(p.x) ^ (hash<int>{}(p.y) + 0x9e3779b9 + (p.x << 6) + (p.x >> 2));
    }
};
}
```

- **rehash 使所有迭代器失效**，但元素引用/指针仍有效。
- 迭代顺序不确定，不可依赖。

### stack / queue

```cpp
// stack：LIFO
value_type& top();                 // 可修改
void push(const value_type& x);
void pop();                        // 返回 void，先 top() 再 pop()
bool empty() const;  size_type size() const;

// queue：FIFO
value_type& front();
value_type& back();
void push(const value_type& x);
void pop();                        // 返回 void
```

```cpp
stack<int> st; st.push(1); int a = st.top(); st.pop();
queue<int> q;  q.push(1);  int b = q.front(); q.pop();
```

### priority_queue

```cpp
const_reference top() const;       // **返回 const 引用，不能改**
void push(const value_type& x);    // O(log n)
template<class... A> void emplace(A&&... args);
void pop();                        // O(log n)，返回 void
bool empty() const;  size_type size() const;
// 没有 clear()、没有迭代器
```

```cpp
// 默认大根堆
priority_queue<int> pq;
pq.push(3); pq.push(1); pq.push(2);
while (!pq.empty()) { int x = pq.top(); pq.pop(); }   // 3 2 1

// 小根堆
priority_queue<int, vector<int>, greater<int>> minq;

// 自定义比较器（注意构造时要把 cmp 传进去）
auto cmp = [](int a, int b) { return a > b; };        // > 得到小根堆
priority_queue<int, vector<int>, decltype(cmp)> pq2(cmp);

// 清空：没有 clear()
pq = priority_queue<int>();
```

- `pair` 默认先比 first 再比 second，且是大根堆。

### bitset

```cpp
constexpr size_t size() const;      // N
bool test(size_t pos) const;        // 越界抛 out_of_range
bool operator[](size_t pos) const;  // 不检查；返回代理引用
bitset& set();  bitset& set(size_t pos, bool v = true);
bitset& reset(); bitset& reset(size_t pos);
bitset& flip();  bitset& flip(size_t pos);
size_t count() const;               // 1 的个数
string to_string() const;
unsigned long to_ulong() const;     // 溢出抛 overflow_error
unsigned long long to_ullong() const;
```

```cpp
bitset<8> b(string("10110000"));
cout << b.count();       // 3
b.set(0);                // 00000001 位
b.flip();                // 全部取反
bitset<8> c = b & bitset<8>(0xFF);
```

- 支持 `& | ^ ~ << >>`，按字并行。
