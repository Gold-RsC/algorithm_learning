#include <iostream>
using namespace std;
int a[10005];
int main() {
    int n;
    cin >> n;
    int i = 0;
    for (; i < (n + 1) / 2; ++i) {
        a[i] = a[n - 1 - i] = 2 * n - 2 - 2 * i;
        cout << a[i] << '\n';
    }
    for (; i < n; ++i) {
        cout << a[i] << '\n';
    }
    return 0;
}
