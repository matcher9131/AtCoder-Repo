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
    int n;
    cin >> n;
    vector<mint> fact(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fact[i] = fact[i - 1] * i;
    }

    for (int k = 1; k <= n; ++k) {
        mint ans = 0;
        for (int j = 1; n - (j - 1) * (k - 1) >= j; ++j) {
            ans += fact[n - (j - 1) * (k - 1)] / fact[n - (j - 1) * (k - 1) - j] / fact[j];
        }
        cout << ans.val() << endl;
    }

    return 0;
}