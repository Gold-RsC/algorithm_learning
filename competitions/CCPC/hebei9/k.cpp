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

bool dir    = true;
const int N = 2e5 + 5;

int a[N];
int n, m;
int p = 0;
int next1[N];
int next0[N];
int next() {
    if (dir) {
        return next1[p];
    }
    else {
        return next0[p];
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];

        next1[i] = (i + 1) % n;
        next0[i] = (i + n - 1) % n;
    }

    for (int i = 1; i <= m; ++i) {
        char c;
        cin >> c;
        switch (c) {
            case 'C': {

                --a[p];
                if (!a[p]) {
                    next1[next0[p]] = next1[p];
                    next0[next1[p]] = next0[p];
                }
                break;
            }
            case 'S': {
                --a[p];
                if (!a[p]) {
                    next1[next0[p]] = next1[p];
                    next0[next1[p]] = next0[p];
                }
                p = next();
                break;
            }
            case 'R': {
                --a[p];
                if (!a[p]) {
                    next1[next0[p]] = next1[p];
                    next0[next1[p]] = next0[p];
                }
                dir = !dir;
                break;
            }
            case 'D': {
                --a[p];
                if (!a[p]) {
                    next1[next0[p]] = next1[p];
                    next0[next1[p]] = next0[p];
                }

                p = next();
                a[p] += 2;
                break;
            }
        }

        p = next();

        // for (int i = 0; i < n; ++i) {
        //     cerr << a[i] << " ";
        // }
        // cerr<<endl;
    }
    for (int i = 0; i < n; ++i) {
        cout << a[i] << "\n";
    }

    return 0;
}
