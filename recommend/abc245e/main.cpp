#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> choco(n), box(m);
    for (ll i = 0; i < n; ++i) {
        cin >> choco[i].first;
    }
    for (ll i = 0; i < n; ++i) {
        cin >> choco[i].second;
    }
    for (ll i = 0; i < m; ++i) {
        cin >> box[i].first;
    }
    for (ll i = 0; i < m; ++i) {
        cin >> box[i].second;
    }

    sort(choco.begin(), choco.end(), greater<>());
    sort(box.begin(), box.end(), greater<>());

    multiset<ll> dBuffer;
    ll j = 0;
    for (ll i = 0; i < n; ++i) {
        for (; j < m; ++j) {
            if (box[j].first < choco[i].first) break;
            dBuffer.insert(box[j].second);
        }
        auto it = dBuffer.lower_bound(choco[i].second);
        if (it == dBuffer.end()) {
            cout << "No" << endl;
            return 0;
        }
        dBuffer.erase(it);
    }

    cout << "Yes" << endl;
    return 0;
}