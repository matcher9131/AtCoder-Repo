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

    string t = "aiueo";

    for (ll i = 0; i < n; ++i) {
        if (t.find(s[i]) == string::npos) cout << s[i];
    }
    cout << endl;

    return 0;
}