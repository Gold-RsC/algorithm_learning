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
vector<int> arr;
vector<int> merge(const vector<int>& a, int mid, int& cnt) {
    int i = 0;
    int j = mid;
    int n = a.size();
    vector<int> ret;
    while (i < mid && j < n) {
        if (a[i] <= a[j]) {
            ret.push_back(a[i++]);
        }
        else {
            ret.push_back(a[j++]);
            cnt += mid - i;
        }
    }
    while (i < mid) {
        ret.push_back(a[i++]);
    }
    while (j < n) {
        ret.push_back(a[j++]);
    }
    return ret;
}
void merge_sort(vector<int>& arr, int& cnt) {
    int len = arr.size();
    if (len <= 1) {
        return;
    }
    int mid = len / 2;
    vector<int> left(arr.begin(), arr.begin() + mid);
    vector<int> right(arr.begin() + mid, arr.end());
    merge_sort(left, cnt);
    merge_sort(right, cnt);
    arr.clear();
    for (auto x : left) {
        arr.push_back(x);
    }
    for (auto x : right) {
        arr.push_back(x);
    }
    arr = merge(arr, mid, cnt);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    while (n) {
        arr.clear();
        while (n--) {
            int x;
            cin >> x;
            arr.push_back(x);
        }
        int cnt = 0;
        merge_sort(arr, cnt);
        cout << cnt << endl;
        cin >> n;
    }

    return 0;
}
