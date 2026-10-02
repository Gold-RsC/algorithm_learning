/**
 * @note 只有满足结合律和差分性质的运算才可使用
 * @note 支持单点修改和区间查询
 * @note i父亲: i+lowbit(i)
 */
int lowbit(int x) {
    return x & (-x);
}
int a[N];
int n;
int c[N];  // 树状数组节点，c[i] 管理 (i - lowbit(i), i] 这段区间

void build() {
    for (int i = 1; i <= n; ++i) {
        c[i] += a[i];
        int j = i + lowbit(i);
        if (j <= n) {
            c[j] += c[i];
        }
    }
}
// 单点更新
void add(int pos, int val) {
    for (int i = pos; i <= n; i += lowbit(i)) {
        c[i] += val;
    }
}
// 前缀和
int presum(int pos) {
    int res = 0;
    for (int i = pos; i > 0; i -= lowbit(i)) {
        res += c[i];
    }
    return res;
}
// 区间查询(左闭右闭)
int query(int left, int right) {
    return presum(right) - presum(left - 1);
}
/**
 * @note 若要求区间修改单点查询，则改为差分数组
 * @note 若要求区间修改区间查询，则维护两个数组d1[],d2[]
 *       d[i]=a[i]-a[i-1]
 *       sum a[i]=sum d[i]*(n-i+1)=sum d[i]*(n+1) + sum d[i]*i
 *       因此d1[i]=d[i],d2[i]=d[i]*i
 */
