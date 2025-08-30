#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll nq;
    cin >> nq;
    vector<ll> next(nq+1, -1);

    for (ll i = 0; i < nq; ++i) {
        ll type;
        cin >> type;
        if (type == 1) {
            ll x;
            cin >> x;
            ll after = next[x];
            if (after >= 0) next[i+1] = after;
            next[x] = i+1;
        } else {
            ll x, y;
            cin >> x >> y;
            ll n1 = x, n2 = y;
            ll sum1 = 0, sum2 = 0;
            while (true) {
                if (n1 >= 0) {
                    n1 = next[n1];
                    if (n1 == y) {
                        cout << sum1 << endl;
                        next[x] = y;
                        break;
                    }
                    sum1 += n1;
                }
                if (n2 >= 0) {
                    n2 = next[n2];
                    if (n2 == x) {
                        cout << sum2 << endl;
                        next[y] = x;
                        break;
                    }
                    sum2 += n2;
                }
            }
        }
    } 

    return 0;
}