#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll nq;
    cin >> nq;

    priority_queue<ll, vector<ll>, greater<ll>> que;
    while (nq--) {
        ll type;
        cin >> type;
        if (type == 1) {
            ll x;
            cin >> x;
            que.push(x);
        } else {
            ll ans = que.top();
            que.pop();
            cout << ans << endl;
        }
    }

    return 0;
}