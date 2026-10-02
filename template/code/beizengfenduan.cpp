/**
 * @brief 倍增分段
 * @note 左闭右开
 */
void beizeng(vector<int> a) {
    int n = a.size();

    for (int l = 0, r = 0; l < n;) {
        int p = 1;

        while (p) {
            // 左闭右开
            if (r + p <= n && check(l, r + p)) {
                r += p;
                p <<= 1;
            }
            else {
                p >>= 1;
            }
        }

        push_ans(l, r);
        l = r;
    }
}
