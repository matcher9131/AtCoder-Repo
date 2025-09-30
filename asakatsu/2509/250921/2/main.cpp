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

    for (ll i = 0; i < n; ++i) {
        if ('0' <= s[i] && s[i] <= '9') {
            if (i+1 < n && '0' <= s[i+1] && s[i+1] <= '9') {
                cout << s[i] << s[i+1] << endl;
                return 0;
            } else {
                cout << s[i] << endl;
                return 0;
            }
        }
    }

    return 0;
}