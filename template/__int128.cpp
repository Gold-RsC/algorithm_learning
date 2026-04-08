#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <string>
#include <cmath>
#include <climits>
using namespace std;

__int128 read() {
    __int128 x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x  = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
istream& operator>>(istream& is, __int128& a) {
    __int128 x = 0, f = 1;
    char ch;
    cin.get(ch);
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = -1;
        cin.get(ch);
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        cin.get(ch);
    }
    a = x * f;
    return is;
}
void print(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) {
        print(x / 10);
    }
    putchar(x % 10 + '0');
}
ostream& operator<<(ostream& os, __int128 x) {
    if (x < 0) {
        os << '-';
        x = -x;
    }
    if (x > 9) {
        os << __int128(x / 10);
    }
    os << char(x % 10 + '0');
    return os;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >>

        return 0;
}
