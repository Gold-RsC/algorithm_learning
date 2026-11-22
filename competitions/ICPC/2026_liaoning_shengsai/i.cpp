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
#include <limits>
#include <climits>
#include <iterator>
#include <cmath>
#include <cstring>
#include <cstdint>
using namespace std;
#define int long long
int monthday[] = {
    0,
    31,
    28,
    31,
    30,
    31,
    30,
    31,
    31,
    30,
    31,
    30,
    31,
};
const int N = 2e5 + 5;
int gongli_month_endday[N];
int gongli_year_endday[N];
vector<pair<int, int>> runyue;

bool is_gongli_runyue(int y) {
    return y % 400 == 0 || (y % 100 != 0 && y % 4 == 0);
}
int gongli2juedui(int y, int m, int d) {
    return gongli_year_endday[y - 1] + gongli_month_endday[m - 1] + (m >= 3 && is_gongli_runyue(y)) + d;
}
void init() {
    int day = 0;
    for (int y = 1900; y <= 2e5 + 5; ++y) {
        day += is_gongli_runyue(y) + 365;
        gongli_year_endday[y] = day;
    }
    day = 0;
    for (int m = 1; m <= 12; ++m) {
        day += monthday[m];
        gongli_month_endday[m] = day;
    }

    day             = 29;
    bool is_dayue   = false;
    int begin       = 0;
    bool begin_flag = false;
    bool end_flag   = false;
    int begin_day   = 0;
    int end_day     = 0;
    for (int y = 1900; y <= 2e5 + 5; ++y) {
        int ans = 0;
        for (int m = 1; m <= 6; ++m) {
            int mid = gongli2juedui(y, m, 6);
            int end = gongli2juedui(y, m, 21);
            day += mid - begin;
            if (day > 29 + is_dayue) {
                day -= 29 + is_dayue;
                is_dayue   = !is_dayue;
                begin_flag = true;
                begin_day  = mid - day + 1;
            }
            else {
                begin_flag = false;
            }
            day += end - mid;
            if (day > 29 + is_dayue) {
                day -= 29 + is_dayue;
                is_dayue = !is_dayue;
                end_flag = true;
                end_day  = end - day;
            }
            else {
                end_flag = false;
            }

            if (begin_flag & end_flag) {
                runyue.push_back({begin_day, end_day});
            }
            begin = end;
        }
        for (int m = 7; m <= 12; ++m) {
            int mid = gongli2juedui(y, m, 8);
            int end = gongli2juedui(y, m, 23);
            day += mid - begin;
            if (day > 29 + is_dayue) {
                day -= 29 + is_dayue;
                is_dayue   = !is_dayue;
                begin_flag = true;
                begin_day  = mid - day + 1;
            }
            else {
                begin_flag = false;
            }
            day += end - mid;
            if (day > 29 + is_dayue) {
                day -= 29 + is_dayue;
                is_dayue = !is_dayue;
                end_flag = true;
                end_day  = end - day;
            }
            else {
                end_flag = false;
            }

            if (begin_flag & end_flag) {
                runyue.push_back({begin_day, end_day});
            }
            begin = end;
        }
    }
}
void query() {
    int s, t;
    cin >> s >> t;
    auto it = lower_bound(runyue.begin(), runyue.end(), pair<int, int>{gongli_year_endday[s - 1] + 1, LLONG_MAX});
    auto jt = lower_bound(runyue.begin(), runyue.end(), pair<int, int>{gongli_year_endday[t], LLONG_MAX});
    cout << jt - it << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    init();
    int q;
    cin >> q;
    while (q--) {
        query();
    }

    return 0;
}
