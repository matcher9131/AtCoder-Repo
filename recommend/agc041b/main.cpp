#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n, m, v, p;
    cin >> n >> m >> v >> p;
    vector<ll> a(n);
    ll sum = 0;
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a.begin(), a.end(), greater<>());

    auto isOK = [&](ll x) -> bool {
        ll i = x-1;
        if (a[i] >= a[p-1]) return true;
        if (a[i] + m < a[p-1]) return false;
        // 自分に不利のない投票のみでMV票を満たせるか
        ll sum = 0;
        // 先頭(p-1)題および自分にそれぞれM票
        sum += p * m;
        // 自分以下の問題にそれぞれM票
        sum += (n - 1 - i) * m;
        // p番目(1-indexed)からi-1番目のそれぞれに自分を超えない票
        for (ll j = p-1; j < i; ++j) {
            sum += a[i] + m - a[j];
        }
        return sum >= m * v;
    };

    ll ok = p;
    ll ng = n+1;

    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if (isOK(mid)) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;
    return 0;
}