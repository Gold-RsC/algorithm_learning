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


// Forward declaration of compare API.
// bool compare(int a, int b);
// return bool means whether a is less than b.
///////////////
bool compare(int a, int b) {
    // some algorithm
    return a < b;
}
///////////////

class Solution {
public:
    vector<int> specialSort(int N) {
        vector<int> ret;
        for (int i = 1; i <= N; ++i) {
            int l = 0, r = ret.size();
            while (l < r) {
                int mid = (l + r) / 2;
                if (compare(ret[mid], i)) {
                    l = mid + 1;
                }
                else {
                    r = mid;
                }
            }
            ret.insert(ret.begin() + l, i);
        }
        return ret;
    }
};
