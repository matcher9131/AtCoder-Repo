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

    char prev = s[0];
    for (ll i = 1; i < n; ++i) {
        if (s[i] >= prev) {
            cout << "No" << endl;
            return 0;
        }
        prev = s[i];
    }

    cout << "Yes" << endl;
    return 0;
}