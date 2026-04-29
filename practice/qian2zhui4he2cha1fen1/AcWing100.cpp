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
const int N = 1e5 + 5;
int n;
int a[N];
int b[N];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        b[i] = a[i] - a[i - 1];
    }

    // 最后的结果是a[i]==b[i]，其中i=1,2,3,...,n

    // 要从b[1]~b[n+1]中选出两个数，应该分成几种情况：
    // 1.1 b[i],b[j]，且一正一负，则尽可能多地匹配
    // 1.2 b[i],b[j]，且同号，匹配只能解决一者的问题
    // 2. b[1],b[j]，则可以解决a[j]的问题
    // 3. b[i],b[n+1]，则可以解决a[i]的问题
    // 4. b[1],b[n+1]，无用

    int p = 0;
    int q = 0;
    for (int i = 2; i <= n; ++i) {
        if (b[i] > 0) {
            p += b[i];
        }
        else {
            q -= b[i];
        }
    }
    // count=abs(p-q)+min(p,q)=max(p,q);
    cout << max(p, q) << endl;
    cout << abs(p - q) + 1;

    return 0;
}
