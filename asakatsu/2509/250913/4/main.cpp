#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    string s, t;
    cin >> s >> t;
    ll n = s.size(), m = t.size();

    if (n < m) {
        cout << "UNRESTORABLE" << endl;
        return 0;
    }

    auto matches = [&](ll startIndex) -> bool {
        if (startIndex + m > n) return false;
        for (ll i = 0; i < m; ++i) {
            if (s[startIndex + i] != '?' && s[startIndex + i] != t[i]) return false;
        }
        return true;
    };

    set<string> ans;
    for (ll i = 0; i < n; ++i) {
        string ss = s;
        if (matches(i)) {
            for (ll j = 0; j < m; ++j) {
                if (ss[i+j] == '?') ss[i+j] = t[j];
            }
            for (ll j = 0; j < n; ++j) {
                if (ss[j] == '?') ss[j] = 'a';
            }
            ans.insert(ss);
        }
    }

    if (ans.empty()) {
        cout << "UNRESTORABLE" << endl;
    } else {
        cout << *ans.begin() << endl;
    }

    return 0;
}