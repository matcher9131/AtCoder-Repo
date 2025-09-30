#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    ll k;
    string s, t;
    cin >> k >> s >> t;
    ll ns = s.size();
    ll nt = t.size();

    if (ns == nt) {
        ll count = 0;
        for (ll i = 0; i < (ll)s.size(); ++i) {
            if (s[i] != t[i]) ++count;
        }
        cout << (count <= 1 ? "Yes" : "No") << endl;
    } else if (abs(ns - nt) == 1) {
        if (ns < nt) {
            swap(s, t);
            swap(ns, nt);
        }
        ll i = 0;
        for (; i < nt; ++i) {
            if (s[i] != t[i]) break;
        }
        cout << (i == nt || s.substr(i+1) == t.substr(i) ? "Yes" : "No") << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}