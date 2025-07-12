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
    ll n;
    cin >> n;
    ll sqrtn = (ll)sqrt(n);

    mint ans = (mint)n * (n+1) / 2;
    for (ll b = 1; b <= sqrtn; ++b) {
        ans -= n / b;
    }
    for (ll k = 1; k <= n / (sqrtn + 1); ++k) {
        ll count = n/k - n/(k+1);
        ans -= (mint)k * count;
    }

    cout << ans.val() << endl;
    return 0;
}