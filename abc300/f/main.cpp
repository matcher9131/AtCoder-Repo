#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n, m, k;
    string s;
    cin >> n >> m >> k >> s;

    vector<ll> indexX;
    vector<ll> sumX(n+1);
    for (ll i = 0; i < n; ++i) {
        if (s[i] == 'x') {
            indexX.push_back(i);
            sumX[i+1] = sumX[i] + 1;
        } else {
            sumX[i+1] = sumX[i];
        }
    }
    ll numX = sumX[n];

    vector<ll> numCircle(numX+1);
    for (ll i = 0; i <= numX; ++i) {
        numCircle[i] = indexX[i];
    }

    ll ans = 0;
    for (ll l = 0; l < n; ++l) {
        if (sumX[n] - sumX[l] > k) {
            ll r = numCircle[k + sumX[l]];
            ans = max(ans, r-l);
        } else {
            ll restK = k - (sumX[n] - sumX[l]);
            ll r = (restK / numX + 1) * n + numCircle[restK % numX];
            ans = max(ans, min(r-l, n*m-l));
        }
    }

    cout << ans << endl;
    return 0;
}