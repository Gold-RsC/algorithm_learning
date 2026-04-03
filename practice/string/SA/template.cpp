#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;
const int N = 114514;

string s;
int sa[N << 1];
int rk[N << 1];

// O(n^2 log n)
void get_sa1(void) {
    iota(sa, sa + s.size(), 0);
    sort(sa, sa + s.size(), [&](int i, int j) {
        return s.substr(i) < s.substr(j);
    });
}
void get_rk_from_sa(void) {
    for (int i = 0; i < s.size(); ++i) {
        rk[sa[i]] = i;
    }
}
// O(n log^2 n)
int oldrk[N << 1];
void get_sa2(void) {
    // 第一层排序
    for (int i = 0; i < s.size(); ++i) {
        sa[i] = i;
        rk[i] = s[i];
    }
    // 二层及以上排序
    for (int w = 1; w < s.size(); w <<= 1) {
        sort(sa, sa + s.size(), [&](int i, int j) {
            // 这里需要两倍空间，否则就得老老实实防止越界
            return rk[i] == rk[j] ? rk[i + w] < rk[j + w]
                                  : rk[i] < rk[j];
        });
        for (int i = 0; i < s.size(); ++i) {
            oldrk[i] = rk[i];
        }
        // 双指针去重
        rk[sa[0]] = 0;
        for (int i = 1, j = 0; i < s.size(); ++i) {
            if (oldrk[sa[i]] == oldrk[sa[i - 1]] &&
                oldrk[sa[i] + w] == oldrk[sa[i - 1] + w]) {
                rk[sa[i]] = j;
            }
            else {
                rk[sa[i]] = ++j;
            }
        }
    }
}
// 还有O(n log n)和O(n)的方法，但不用学

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    cin >> s;

    get_sa2();
    get_rk_from_sa();

    for (int i = 0; i < s.size(); ++i) {
        cout << sa[i] << ' ';
    }
    cout << endl;
    for (int i = 0; i < s.size(); ++i) {
        cout << rk[i] << ' ';
    }
    return 0;
}
