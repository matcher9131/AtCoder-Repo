#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n, m, h, k;
    string s;
    cin >> n >> m >> h >> k >> s;
    set<pair<ll, ll>> item;
    for (ll i = 0; i < m; ++i) {
        ll x, y;
        cin >> x >> y;
        item.emplace(x, y);
    }

    ll hp = h;
    ll x = 0, y = 0;
    for (ll i = 0; i < n; ++i) {
        switch (s[i]) {
            case 'R': ++x; break;
            case 'L': --x; break;
            case 'U': ++y; break;
            case 'D': --y; break;
        }
        --hp;
        if (hp < 0) {
            cout << "No" << endl;
            return 0;
        }
        if (hp < k) {
            auto it = item.find({x, y});
            if (it != item.end()) {
                hp = k;
                item.erase(it);
            }
        }
    }

    cout << "Yes" << endl;
    return 0;
}