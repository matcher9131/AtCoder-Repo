#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll w, n1, n2;
    cin >> w >> n1 >> n2;

    vector<ll> v1(n1), l1(n1);
    for (ll i = 0; i < n1; ++i) {
        cin >> v1[i] >> l1[i];
    }
    vector<ll> v2(n2), l2(n2);
    for (ll i = 0; i < n2; ++i) {
        cin >> v2[i] >> l2[i];
    }

    vector<ll> sumL1(n1);
    sumL1[0] = l1[0];
    for (ll i = 1; i < n1; ++i) {
        sumL1[i] = sumL1[i-1] + l1[i];
    }
    vector<ll> sumL2(n2);
    sumL2[0] = l2[0];
    for (ll i = 1; i < n2; ++i) {
        sumL2[i] = sumL2[i-1] + l2[i];
    }

    ll ans = 0;
    ll i = 0, j = 0, k = 0;
    while (i < w) {
        ll ni = sumL1[j] > sumL2[k] ? sumL2[k] : sumL1[j];
        if (v1[j] == v2[k]) ans += ni - i;
        i = ni;
        if (sumL1[j] > sumL2[k]) ++k;
        else if (sumL1[j] < sumL2[k]) ++j;
        else {
            ++j;
            ++k;
        }
    }
    
    cout << ans << endl;
    return 0;
}