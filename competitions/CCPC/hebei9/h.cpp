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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    if (s.substr(s.size() - 12, 12) == "isallyouneed") {
        cout << "Yes\n";
        cout << s.substr(0, s.size() - 12);
    }
    else {
        cout << "No";
    }

    return 0;
}
