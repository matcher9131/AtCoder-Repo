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
using mint = atcoder::modint998244353;

int main() {
    int n, k;
    cin >> n >> k;
    vector<mint> a(n);
    for (int i = 0; i < n; ++i) {
        int ai;
        cin >> ai;
        a[i] = ai;
    }

    vector<mint> s(n+1);
    for (int i = 0; i < n; ++i) {
        s[i+1] = s[i] + a[i];
    }

    // ssp[i][x]: x <= j <= N における sj^i の和 (0 <= i <= k)
    vector<vector<mint>> ssp(k + 1, vector<mint>(n + 1));
    for (int i = 0; i < k + 1; ++i) {
        ssp[i][n] = s[n].pow(i);
        for (int x = n - 1; x >= 0; --x) {
            ssp[i][x] = ssp[i][x+1] + s[x].pow(i);
        }
    }

    vector<mint> fact(k+1);
    fact[0] = 1;
    for (int i = 1; i <= k; ++i) {
        fact[i] = fact[i-1] * i;
    }

    mint ans = 0;
    for (int r = 0; r <= k; ++r) {
        mint t = 0;
        for (int i = 0; i < n; ++i) {
            t += (-s[i]).pow(r) * ssp[k-r][i+1];
        }
        ans += t * fact[k] / (fact[r] * fact[k-r]);
    }

    cout << ans.val() << endl;
    return 0;
}