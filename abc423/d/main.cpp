#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), b(n), c(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i] >> b[i] >> c[i];
    }

    vector<ll> ans(n);
    priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> que;
    queue<ll> waiting;
    for (ll i = 0; i < n; ++i) {
        que.emplace(a[i], 1, i);
    }
    ll rest = k;
    while (!que.empty()) {
        auto [t, type, i] = que.top();
        que.pop();
        if (type == 0) {
            rest += c[i];
            while (!waiting.empty()) {
                ll j = waiting.front();
                if (rest >= c[j]) {
                    waiting.pop();
                    ans[j] = t;
                    rest -= c[j];
                    que.emplace(t + b[j], 0, j);
                    // printf("in from waiting %lld, t = %lld\n", j, t);
                } else {
                    break;
                }
            }
        } else {
            if (waiting.empty() && rest >= c[i]) {
                ans[i] = t;
                rest -= c[i];
                que.emplace(t + b[i], 0, i);
                // printf("in %lld, t = %lld\n", i, t);
            } else {
                // printf("waiting %lld\n", i);
                waiting.push(i);
            }
        }
    }

    for (ll i = 0; i < n; ++i) {
        cout << ans[i] << endl;
    }

    return 0;
}