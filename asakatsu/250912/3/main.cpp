#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    ll n;
    cin >> n;
    set<ll> temp;
    vector<ll> ok;
    for (ll i = 0; i < n; ++i) {
        ll ai;
        cin >> ai;
        if (temp.contains(ai)) {
            ok.push_back(ai);
            temp.erase(ai);
        } else {
            temp.insert(ai);
        }
    }

    if ((ll)ok.size() < 2) {
        cout << 0 << endl;
        return 0;
    }

    sort(ok.begin(), ok.end(), greater<>());
    cout << ok[0] * ok[1] << endl;

    return 0;
}