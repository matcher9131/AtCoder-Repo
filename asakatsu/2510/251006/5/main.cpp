#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

int main() {
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    ll n = s1.size();

    vector<ll> c1(26), c2(26), c3(26);
    for (ll i = 0; i < n; ++i) {
        ++c1[s1[i] - 'A'];
        ++c2[s2[i] - 'A'];
        ++c3[s3[i] - 'A'];
    }

    vector<ll> min1(26), min2(26);
    for (ll j = 0; j < 26; ++j) {
        if (c1[j] < c3[j]) min2[j] = c3[j] - c1[j];
        if (c2[j] < c3[j]) min1[j] = c3[j] - c2[j];
    }

    cout << (accumulate(min1.begin(), min1.end(), 0LL) <= n/2 && accumulate(min2.begin(), min2.end(), 0LL) <= n/2 ? "YES" : "NO") << endl;

    return 0;
}