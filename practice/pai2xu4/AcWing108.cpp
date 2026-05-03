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
const int N = 501;
int n;
int a[N * N];
int b[N * N];
int tmp[N * N];
int merge(int arr[], int l, int r) {
    int mid = (l + r) / 2;
    int i   = l;
    int j   = mid;
    int k   = l;
    int cnt = 0;
    while (i < mid && j < r) {
        if (arr[i] <= arr[j]) {
            tmp[k++] = arr[i++];
        }
        else {
            tmp[k++] = arr[j++];
            cnt += mid - i;
        }
    }
    while (i < mid) {
        tmp[k++] = arr[i++];
    }
    while (j < r) {
        tmp[k++] = arr[j++];
    }
    for (k = l; k < r; ++k) {
        arr[k] = tmp[k];
    }
    return cnt;
}
int merge_sort(int arr[], int l, int r) {
    if (r - l <= 1) {
        return 0;
    }
    int mid = (l + r) / 2;
    int cnt = 0;
    cnt += merge_sort(arr, l, mid);
    cnt += merge_sort(arr, mid, r);
    cnt += merge(arr, l, r);
    return cnt;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    while (!cin.eof()) {
        for (int k = n * n, i = 0; k--;) {
            int x;
            cin >> x;
            if (x) {
                a[i++] = x;
            }
        }
        for (int k = n * n, i = 0; k--;) {
            int x;
            cin >> x;
            if (x) {
                b[i++] = x;
            }
        }
        cout << (((merge_sort(a, 0, n * n - 1) - merge_sort(b, 0, n * n - 1)) % 2 == 0) ? "TAK\n" : "NIE\n");
        cin >> n;
    }

    return 0;
}
