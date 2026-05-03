#include <iostream>
#include <iomanip>
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
#include <cmath>
#include <climits>
#include <cstring>
using namespace std;


bool check(int l, int r) {
    return true;
}
void beizeng(vector<int> a) {
    int n = a.size();

    for (int l = 0, r = 0; l < n;) {
        int p = 1;

        while (p) {
            // ×ó±ÕÓÒ¿ª
            if (r + p <= n && check(l, r + p)) {
                r += p;
                p <<= 1;
            }
            else {
                p >>= 1;
            }
        }

        (l, r);
        l = r;
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    return 0;
}
