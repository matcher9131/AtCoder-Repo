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
#include <atcoder/fenwicktree>
using namespace std;
using ll = long long;
constexpr ll INF = 1e16;
using mint = atcoder::modint998244353;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ll m = 2e5+1;
    atcoder::fenwick_tree<mint> count(m), sum(m);

    mint numer = 0;
    for (ll i = 0; i < n; ++i) {
        mint smallerCount = count.sum(0, a[i]);
        mint largerSum = sum.sum(a[i], m);
        numer += (2 * smallerCount + 1) * a[i] + 2 * largerSum;
        cout << (numer / ((mint)(i+1) * (i+1))).val() << endl;
        count.add(a[i], 1);
        sum.add(a[i], a[i]);
    }

    return 0;
}