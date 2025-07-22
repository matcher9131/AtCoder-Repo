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
using namespace std;
using ll = long long;

constexpr ll INF = 1e16;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> p(n);
    for (ll i = 0; i < n; ++i) {
        cin >> p[i];
        --p[i];
    }
    vector<ll> c(n);
    for (ll i = 0; i < n; ++i) {
        cin >> c[i];
    }

    ll ans = -INF;
    for (ll i = 0; i < n; ++i) {
        ll v = i;
        ll cycleSum = 0;
        ll cycleLength = 0;
        do {
            ++cycleLength;
            cycleSum += c[v];
            v = p[v];
        } while (v != i);

        ll sum = 0;
        ll length = 0;
        do {
            ++length;
            sum += c[v];
            if (length > k) break;
            ll cycleCount = (k - length) / cycleLength;
            ans = max(ans, sum + cycleCount * max(0LL, cycleSum));
            v = p[v];
        } while (v != i);
    }

    cout << ans << endl;
    return 0;
}