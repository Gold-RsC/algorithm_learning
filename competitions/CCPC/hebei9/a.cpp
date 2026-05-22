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
#define int long long
int n;
const int N = 2e5 + 5;
int a[N][2];
int pre[N][2];
#define brz()   cout << "brz\n"
#define Mandy() cout << "Mandy\n"
#define draw()  cout << "draw\n"
void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i][0];
        pre[i][0] = pre[i - 1][0] + a[i][0];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> a[i][1];
        pre[i][1] = pre[i - 1][1] + a[i][1];
    }

    if (n & 1) {
        int O  = pre[n][1] - pre[n / 2 + 1][1];
        int V  = pre[n / 2][0];
        int S1 = pre[n][0] - pre[n / 2 + 1][0];
        int S2 = pre[n / 2][1];
        int G1 = a[n / 2 + 1][0];
        int G2 = a[n / 2 + 1][1];

        if (V + S2 > O + G1 + G2 + S1) {
            Mandy();
        }
        else if (V + S2 < O + G1 + G2 + S1) {
            if (V + G1 + S1 < O + G2 + S2 || V + G1 + G2 + S2 < O + S1) {
                brz();
            }
            else if (V + G1 + S1 == O + G2 + S2 || V + G1 + G2 + S2 == O + S1) {
                draw();
            }
            else {
                Mandy();
            }
        }
        else {
            if (V + G1 + S1 < O + G2 + S2 || V + G1 + G2 + S2 < O + S1) {
                draw();
            }
            else if (V + G1 + S1 == O + G2 + S2 || V + G1 + G2 + S2 == O + S1) {
                draw();
            }
            else {
                Mandy();
            }
        }
    }
    else {
        int O  = pre[n][1] - pre[n / 2 + 1][1];
        int V  = pre[n / 2][0];
        int S1 = pre[n][0] - pre[n / 2 + 1][0];
        int S2 = pre[n / 2][1];
        int G1 = a[n / 2 + 1][1];
        int G2 = a[n / 2 + 1][0];

        if (O + S1 > V + G1 + G2 + S2) {
            brz();
        }
        else if (O + S1 == V + G1 + G2 + S2) {
            if (O + G1 + G2 + S1 < V + S2 || O + G1 + S2 < V + G2 + S1) {
                draw();
            }
            else if (O + G1 + G2 + S1 == V + S2 || O + G1 + S2 == V + G2 + S1) {
                draw();
            }
            else {
                brz();
            }
        }
        else {
            if (O + G1 + G2 + S1 < V + S2 || O + G1 + S2 < V + G2 + S1) {
                Mandy();
            }
            else if (O + G1 + G2 + S1 == V + S2 || O + G1 + S2 == V + G2 + S1) {
                draw();
            }
            else {
                brz();
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
