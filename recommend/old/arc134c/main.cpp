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
constexpr ll INF = 1e16;
using mint = atcoder::modint998244353;

mint combination(ll n, ll r) {
    mint numer = 1, denom = 1;
    for (ll i = 0; i < r; ++i) {
        numer *= (n - i);
        denom *= (i + 1);
    }
    return numer / denom;
}

mint duplicatedCombination(ll h, ll r) {
    return combination(h + r - 1, r - 1);
}

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    ll sum = 0;
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    ll remainder0 = a[0] - (sum - a[0]) - k;
    if (remainder0 < 0) {
        cout << 0 << endl;
        return 0;
    }

    mint ans = duplicatedCombination(remainder0, k);
    for (ll i = 1; i < n; ++i) {
        ans *= duplicatedCombination(a[i], k);
    }

    cout << ans.val() << endl;
    return 0;
}