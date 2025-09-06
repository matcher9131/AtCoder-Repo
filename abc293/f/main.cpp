#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

__int128_t pow128(__int128_t x, ll n) {
    __int128_t ans = 1;
    while (n > 0) {
        if (n & 1) ans *= x;
        x *= x;
        n >>= 1;
    }
    return ans;
}

bool meets(ll x, ll b) {
    while (x > 0) {
        if (x % b > 1) return false;
        x /= b;
    }
    return true;
}

void solve() {
    ll n;
    cin >> n;

    unordered_set<ll> ans;
    ans.insert(2);

    // k = 1
    ans.insert(n);
    if (n > 2) ans.insert(n-1);
    // k = 2
    {
        ll b = sqrt(n);
        if (b > 1 && b*b == n) ans.insert(b);
    }
    {
        ll b = sqrt(n-1);
        if (b > 1 && b*b == n-1) ans.insert(b);
    }
    {
        ll left = 0, right = sqrt(n)+1;
        while (right - left > 1) {
            ll mid = (left + right) / 2;
            if (mid * mid + mid == n) {
                if (mid > 1) ans.insert(mid);
                break;
            }
            if (mid * mid + mid < n) left = mid;
            else right = mid;
        }
    }
    {
        ll left = 0, right = sqrt(n)+1;
        while (right - left > 1) {
            ll mid = (left + right) / 2;
            if (mid * mid + mid + 1 == n) {
                if (mid > 1) ans.insert(mid);
                break;
            }
            if (mid * mid + mid + 1 < n) left = mid;
            else right = mid;
        }
    }

    for (ll k = 3; k <= 37; ++k) {
        for (__int128_t b = pow(n/2, 1.0/k); pow128(b, k) <= n; ++b) {
            if (b <= 2) continue;
            if (meets(n, b)) ans.insert(b);
        }
    }

    cout << ans.size() << endl;
}

int main() {
    ll t;
    cin >> t;
    
    while (t--) {
        solve();
    }

    return 0;
}