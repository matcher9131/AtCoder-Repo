#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <climits>
#include <cfloat>
#include <utility>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <numeric>
#include <functional>
#include <atcoder/modint>
using namespace std;
using ull = unsigned long long;
using mint = atcoder::modint998244353;

int main() {
    ull n, m;
    cin >> n >> m;

    mint base2 = 2;
    mint ans = 0;
    for (int bi = 60; bi >= 0; --bi) {
        if (n & 1ULL << bi) {
            int uc = popcount((n & ULLONG_MAX >> (bi + 1) << (bi + 1)) & (m & ULLONG_MAX >> (bi + 1) << (bi + 1)));
            int lc = popcount(m & ((1ULL << bi) - 1));
            if (lc > 0) {
                ans += base2.pow(bi - lc) * lc * base2.pow(lc - 1);
            }
            ans += uc * base2.pow(bi);
        }
    }
    ans += popcount(n & m);

    cout << ans.val() << endl;
    return 0;
}