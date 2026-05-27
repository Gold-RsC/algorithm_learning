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

string s = "PCAS03,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0";
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    char a = 0;
    for (char x : s) {
        a ^= x;
    }
    printf("%2.2X", a);

    return 0;
}
