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
    ll n, m, k;
    cin >> n >> m >> k;

    if (n == 1) {
        cout << ((mint)k).pow(m).val() << endl;
        return 0;
    } else if (m == 1) {
        cout << ((mint)k).pow(n).val() << endl;
        return 0;
    }

    mint ans = 0;
    for (ll i = 1; i <= k; ++i) {
        mint nr = ((mint)i).pow(n) - ((mint)(i-1)).pow(n);
        mint nc = ((mint)(k-i+1)).pow(m);
        ans += nr * nc;
    }

    cout << ans.val() << endl;
    return 0;
}