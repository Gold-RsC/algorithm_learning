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

const int N = 1e3 + 5;
/**
 * @name Floyd
 * @details time O(n^3), spaceO(n^2),
 * @details 适用于所有图，无关边权正负
 */
// f[x][y]:=x->y的最短路
int f[N][N];
void Floyd2() {
    for (int k = 1; k <= n; ++k) {
        for (int x = 1; x <= n; ++x) {
            for (int y = 1; y <= n; ++y) {
                f[x][y] = min(f[x][y], f[x][k] + f[k][y]);
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    return 0;
}
