#include <iostream>
using namespace std;
int bihua[10] = {13, 1, 2, 3, 5, 4, 4, 2, 2, 2};
uint64_t ans;
int y = 2000, m = 1, d = 1;
bool is_runyue() {
    return y % 4 == 0 ? y % 100 == 0 ? y % 400 == 0 : true : false;
}
int get_bihua() {
    return bihua[y / 1000] + bihua[y / 100 % 10] + bihua[y / 10 % 10] + bihua[y % 10] + bihua[m / 10] + bihua[m % 10] +
           bihua[d / 10] + bihua[d % 10];
}
void get_next() {
    switch (m) {
        case 1: {
            if (d == 31) {
                m++;
                d = 1;
                return;
            }
            break;
        }
        case 2: {
            if (d == 29 && is_runyue()) {
                m++;
                d = 1;
                return;
            }
            else if (d == 28 && !is_runyue()) {
                m++;
                d = 1;
                return;
            }
            break;
        }
        case 3: {
            if (d == 31) {
                m++;
                d = 1;
                return;
            }
            break;
        }
        case 4: {
            if (d == 30) {
                m++;
                d = 1;
                return;
            }
            break;
        }
        case 5: {
            if (d == 31) {
                m++;
                d = 1;
                return;
            }
            break;
        }
        case 6: {
            if (d == 30) {
                m++;
                d = 1;
                return;
            }
            break;
        }
        case 7: {
            if (d == 31) {
                m++;
                d = 1;
                return;
            }
            break;
        }
        case 8: {
            if (d == 31) {
                m++;
                d = 1;
                return;
            }
            break;
        }
        case 9: {
            if (d == 30) {
                m++;
                d = 1;
                return;
            }
            break;
        }
        case 10: {
            if (d == 31) {
                m++;
                d = 1;
                return;
            }
            break;
        }
        case 11: {
            if (d == 30) {
                m++;
                d = 1;
                return;
            }
            break;
        }
        case 12: {
            if (d == 31) {
                y++;
                m = 1;
                d = 1;
                return;
            }
            break;
        }
    }
    d++;
}
int main() {
    while (1) {
        if (get_bihua() > 50) {
            ans++;
        }
        cout << y << m << d << endl;
        if (y == 2024 && m == 4 && d == 13) {
            break;
        }
        get_next();
    }
    cout << ans;
    return 0;
}
// 3228
