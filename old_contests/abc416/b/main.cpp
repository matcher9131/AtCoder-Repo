#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    string s;
    cin >> s;
    int n = s.size();

    string t(n, '.');
    bool ok = true;
    for (ll i = 0; i < n; ++i) {
        if (s[i] == '#') {
            t[i] = '#';
            ok = true;
        } else if (ok) {
            t[i] = 'o';
            ok = false;
        }
    }

    cout << t << endl;
    return 0;
}