/**
 * @brief 随机数生成函数
 */
// 基于硬件的均匀分布随机数生成器
static random_device rd;
// 32位梅森缠绕器(@ret u32)
// 可替换为64位mt19937_64
static mt19937 gen(rd());
// uniform_int_distribution为整数，左闭右闭[]
// 浮点数用uniform_real_distribution，左闭右开[)
static uniform_int_distribution<int> dist(1, 100);
int get_rand() {
    return dist(gen);
}

/**
 * @brief 随机打乱
 */
void algo_shffle(vector<int>& v) {
    shuffle(v.begin(), v.end(), gen);  // 此处gen可换为一个随机数发生函数
}

/**
 * @brief 随机挑选
 */
vector<int> algo_sample(const vector<int>& v, int n) {
    vector<int> ret;
    sample(v.begin(), v.end(), ret.end(), n, gen);
    return ret;
}
