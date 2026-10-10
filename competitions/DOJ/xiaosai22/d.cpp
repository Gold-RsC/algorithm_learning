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
#include <cmath>
#include <climits>
#include <cstring>
#include <cstdint>
using namespace std;
#define int long long

int A[3][4];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);


    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> A[i][j];
        }
        A[i][0] -= A[i][3];
    }
    cout <<                                //
        A[0][0] * A[1][1] * A[2][2]        // aaaa
            + A[0][1] * A[1][2] * A[2][0]  // aaaa
            + A[0][2] * A[1][0] * A[2][1]  // aaaa
            - A[0][2] * A[1][1] * A[2][0]  // aaaa
            - A[0][1] * A[1][0] * A[2][2]  // aaaa
            - A[0][0] * A[1][2] * A[2][1];
    return 0;
}
