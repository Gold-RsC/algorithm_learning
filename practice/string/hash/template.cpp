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
#include <cmath>
#include <cstring>
#include <cstdint>
using namespace std;
#define int long long
const size_t base = 131;
const size_t mod1 = 212370440130137957, mod2 = 1e9 + 7;
size_t get_hash1(const string& s) {
    size_t ans = 0;
    for (const auto& c : s) {
        ans = (ans * base + c) % mod1;
    }
    return ans;
}
size_t get_hash2(const string& s) {
    size_t ans = 0;
    for (const auto& c : s) {
        ans = (ans * base + c) % mod2;
    }
    return ans;
}
bool is_equal(const string& s1, const string& s2) {
    return get_hash1(s1) == get_hash1(s2) && get_hash2(s1) == get_hash2(s2);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);


    return 0;
}
