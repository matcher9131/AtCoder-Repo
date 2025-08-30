#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    vector<ll> a(10);
    cin >> a[0] >> a[1];

    auto f = [](ll x) -> ll {
        string s = to_string(x);
        reverse(s.begin(), s.end());
        return stoll(s, nullptr, 10);
    };

    for (ll i = 2; i < 10; ++i) {
        a[i] = f(a[i-2] + a[i-1]);
    }

    cout << a[9] << endl;

    return 0;
}