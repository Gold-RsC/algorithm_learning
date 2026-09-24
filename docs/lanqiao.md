# 考前提醒

## 考前准备

- 身份证、准考证、***笔、草稿纸***
- 考前整理一下`../template/`

## 习惯问题

- 调配置：-std=c++11
- 抬手式`../template/@OI.cpp`
- 万恶的`DEVC++`，为了代码补全，模板代码要把头文件全写出来！！！
- 分题号写，别写串了！！！
- 调试代码一律用`cerr`！！！
- 先暴力，做完一轮再回来精做！！！！！！！！
- 用`#define int int64_t`，不要用`uint64_t`！！！！！
- 最大最小值先预先赋值`LLONG_MAX`,`LLONG_MIN`！！！
- 暴力：能dfs直接dfs，能筛直接枚举答案筛

## 知识问题

- 记住`equal_range=[lower_bound,upper_bound)`，`binary_search=is_valid(equal_range) (->bool)`
- 把`permutation`拼对了！！！
- 记住`stable_sort`
- 正向不好求，可以跳过条件直接找目标答案，再验证对不对
- 记住`前缀和`、`差分`
- 遇到环变成两倍的链

## 由数据范围推算法

- $1 \le n \le 15$: 状态压缩
- $1 \le n \le 500$: O(n^3)
- $1 \le n \le 2000$: O(n^2)
- $1 \le n \le 1e5$: 桶 /  O(n logn)/O(n \sqrt{n})
- 更大 : O(n) / O(log n) / O(\sqrt{n})