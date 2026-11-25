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
#include <iterator>
#include <cmath>
#include <cstring>
#include <cstdint>
using namespace std;
#define int long long

/**
 * @brief 组合博弈
 * @note
 *   1. 一个状态是必败状态，当且仅当它的所有后继都是必胜状态
 *      一个状态是必胜状态，当且仅当它存在一个后继是必败状态
 *   2. 后继:
 *        一个局面经过一次移动得到的局面(时间上)
 *      子游戏:
 *        整体游戏在结构上被拆分成互不影响的独立部分(结构上)
 *   3. 游戏的和(和博弈):
 *        两个同时进行且互不干扰的子游戏组成的游戏，玩家每一步能且只能选择其中一个子游戏移动一步
 *        且在两个游戏都无法移动时结束
 *        G+H = {g+H|g \in G}并{G+h|h \in H}
 *   4. 游戏的等价关系:
 *        若G1+H与G2+H同处必败或必胜，则G1与G2等价
 *      引理:
 *        G与G+P等价，P是必败游戏
 *        G与H等价，当且仅当G+H是必败游戏
 *   5. Grundy函数(SG值/Nim数):
 *        局面x，后继局面集合F(x)，SG(x)=mex{SG(y)|y \in F(x)}
 *        SG=0时必败，否则必胜
 *      Sprague–Grundy定理:
 *        对于由若干独立子游戏组成的和博弈，总局面的Grundy函数等于各子游戏SG值的异或和
 *        SG(G1+G2+...+Gn)=SG(G1)^SG(G2)^...^SG(Gn)
 */
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);


    return 0;
}
