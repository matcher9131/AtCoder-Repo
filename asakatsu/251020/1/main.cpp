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
    ll a, b;
    cin >> a >> b;
    string s;
    cin >> s;
    ll n = s.size();

    ll i = 0;
    for (; i < a; ++i) {
        if (s[i] < '0' || '9' < s[i]) {
            cout << "No" << endl;
            return 0;
        }
    }
    if (s[i] != '-') {
        cout << "No" << endl;
        return 0;
    }
    ++i;
    for (; i < n; ++i) {
        if (s[i] < '0' || '9' < s[i]) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}