#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }

    sort(a.begin(), a.end());

    vector<pair<int, int>> ans;
    ans.push_back(a[0]);
    for (auto [l, r] : a) {
        if (ans.back().second < l) {
            ans.push_back({l, r});
        }
        else {
            ans.back().second = max(ans.back().second, r);
        }
    }
    int youren = 0;
    int wuren  = 0;
    for (int i = 0; i < ans.size(); ++i) {
        auto [l, r] = ans[i];
        if (i) {
            wuren = max(wuren, l - ans[i - 1].second);
        }
        youren = max(youren, r - l);
    }
    cout << youren << " " << wuren;
    return 0;
}
