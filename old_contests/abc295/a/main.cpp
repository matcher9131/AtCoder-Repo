#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n;
    cin >> n;
    bool b = false;
    for (ll i = 0; i < n; ++i) {
        string s;
        cin >> s;
        if (s == "and" || s == "not" || s == "that" || s == "the" || s == "you") {
            b = true;
        }
    }

    cout << (b ? "Yes" : "No") << endl;
    return 0;
}