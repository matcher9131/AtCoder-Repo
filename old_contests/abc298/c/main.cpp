#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n, nq;
    cin >> n >> nq;

    vector<map<ll, ll>> box(n);
    vector<set<ll>> number(2e5);

    while (nq--) {
        ll type;
        cin >> type;
        if (type == 1) {
            ll i, j;
            cin >> i >> j;
            --i;
            --j;
            ++box[j][i];
            number[i].insert(j);
        } else if (type == 2) {
            ll j;
            cin >> j;
            --j;
            for (auto it = box[j].begin(); it != box[j].end(); ++it) {
                auto [x, c] = *it;
                for (ll ci = 0; ci < c; ++ci) {
                    if (it != box[j].begin() || ci > 0) cout << " ";
                    cout << x+1;
                }
            }
            cout << endl;
        } else {
            ll i;
            cin >> i;
            --i;
            for (auto it = number[i].begin(); it != number[i].end(); ++it) {
                if (it != number[i].begin()) cout << " ";
                cout << *it + 1;
            }
            cout << endl;
        }
    }

    return 0;
}