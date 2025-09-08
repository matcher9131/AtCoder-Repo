#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n;
    cin >> n;
    vector<ll> x(n), y(n);
    for (ll i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    mt19937 gen(42);
    uniform_int_distribution<> dist(0, n-1);

    set<pair<ll, ll>> used;
    for (ll ti = 0; ti < 100; ++ti) {
        int i = dist(gen);
        int j = dist(gen);
        if (i == j || used.contains({i,j}) || used.contains({j,i})) {
            --ti;
            continue;
        }

        ll a = y[i] - y[j];
        ll b = -(x[i] - x[j]);
        ll c = -(a * x[i] + b * y[i]);
        ll count = 0;
        for (ll k = 0; k < n; ++k) {
            if (a * x[k] + b * y[k] + c == 0) ++count;
        }
        if (count > n/2) {
            cout << "Yes" << endl;
            cout << a << " " << b << " " << c << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}