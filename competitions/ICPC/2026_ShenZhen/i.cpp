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
vector<pair<vector<int>, vector<int>>> ans[100];
void init() {
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    int t;
    cin >> t;
    while (t--) {
        int d;
        cin >> d;
        if (d == 1) {
            cout << "Yes\n";
            cout << "0 0 0 0 0 0 0 0 0 0 0 0\n";
        }
        else if (d == 2) {
            cout << "Yes\n";
            cout << "0 0 0 0 0 0 0 0 0 0 0 1\n";
        }
        else if (d == 3) {
            cout << "Yes\n";
            cout << "0 0 0 0 0 0 1 2 0 0 0 0\n";
        }
        else if (d == 4) {
            cout << "Yes\n";
            cout << "0 0 0 0 0 0 1 2 3 0 0 0\n";
        }
        else if (d == 5) {
            cout << "Yes\n";
            cout << "0 0 0 0 0 0 1 2 3 4 0 0\n";
        }
        else if (d == 6) {
            cout << "Yes\n";
            cout << "0 0 0 0 0 0 1 2 3 4 5 0\n";
        }
        else if (d == 7) {
            cout << "Yes\n";
            cout << "0 6 0 0 0 0 1 2 3 4 5 0\n";
        }
        else if (d == 8) {
            cout << "Yes\n";
            cout << "0 6 7 0 0 0 1 2 3 4 5 0\n";
        }
        else if (d == 11) {
            cout << "Yes\n";
            cout << "0 6 7 8 0 0 1 2 3 4 5 0\n";
        }
        else if (d == 22) {
            cout << "Yes\n";
            cout << "0 6 7 8 1 0 1 2 3 4 5 0\n";
        }
        else if (d == 33) {
            cout << "Yes\n";
            cout << "0 6 7 8 1 2 1 2 3 4 5 0\n";
        }
        else {
            cout << "No\n";
        }
    }
    return 0;
}
