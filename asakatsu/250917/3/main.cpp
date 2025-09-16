#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    string s;
    cin >> s;
    ll n = s.size();

    ll ans = 0;
    bool isZero = false;
    for (ll i = 0; i < n; ++i) {
        if (s[i] == '0') isZero = true;
        else if (s[i] == '+') {
            if (!isZero) ++ans;
            isZero = false;
        }
    }
    if (!isZero) ++ans;
    cout << ans << endl;

    return 0;
}