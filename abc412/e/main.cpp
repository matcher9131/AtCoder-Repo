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


int main() {
    ll l, r;
    cin >> l >> r;

    ll m = 1e7;
    // √R以下が素数かどうか
    vector<bool> isPrime(m+1, true);
    isPrime[0] = isPrime[1] = false;
    // √R以下の素数を素因数に持つかどうか
    vector<bool> visited(r - l);

    ll ans = 1; // Lは必ず対象
    for (ll p = 2; p * p <= r; ++p) {
        // エラトステネスの篩（通常版）
        if (!isPrime[p]) continue;
        for (ll x = 2*p; x <= m; x += p) {
            isPrime[x] = false;
        }

        // エラトステネスの区間篩
        // start: Aより大きく最小のpの倍数
        ll start = (l / p + 1) * p;
        for (ll x = start; x <= r; x += p) {
            if (visited[x - (l+1)]) continue;
            visited[x - (l+1)] = true;
            ll y = x;
            while (y % p == 0) y /= p;
            if (y == 1) ++ans;
        }
    }

    for (const bool b : visited) {
        if (!b) ++ans;
    }

    cout << ans << endl;
    return 0;
}