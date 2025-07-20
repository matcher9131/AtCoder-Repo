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
using ll = long long;
using mint = atcoder::modint1000000007;

int main() {
    int n, k;
    cin >> n >> k;

    vector<mint> fact(2 * n);
    fact[0] = 1;
    for (int i = 1; i < 2*n; ++i) {
        fact[i] = fact[i-1] * i;
    }

    mint ans = 0;
    for (int i = 0; i <= min(k, n-1); ++i) {
        // 空き部屋がiになる分け方：
        // 空き部屋の選び方 C(n, i)
        // i人を空いていないn-i部屋に入れる選び方 H(i, n-i) = C(n-1, i)
        // ※n-i人は1人ずつ部屋に配置する必要があるため、自由に配置できるのはi人
        ans += fact[n] / (fact[i] * fact[n-i]) * fact[n-1] / (fact[n-1-i] * fact[i]);
    }

    cout << ans.val() << endl;
    return 0;
}