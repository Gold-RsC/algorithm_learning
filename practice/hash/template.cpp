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
struct Person {
    string name;
    int age;
};
template <>
struct hash<Person> {
    size_t operator()(const Person& p) const noexcept {
        size_t h1 = hash<string>{}(p.name);
        size_t h2 = hash<int>{}(p.age);
        return h1 ^ (h2 + 0x9e3779b97f4a7c15ULL + (h1 << 6) + (h1 >> 2));
    }
};
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);


    return 0;
}
