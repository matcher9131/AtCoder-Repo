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

    double ans = 0;
    for (ll i = 0; i < n; ++i) {
        for (ll j = i+2; j < n; ++j) {
            if (s[i] == 't' && s[j] == 't') {
                int count = 0;
                for (ll k = i; k <= j; ++k) {
                    if (s[k] == 't') ++count;
                }
                ans = max(ans, (double)(count - 2) / (j - i + 1 - 2));
            }
        }
    }

    cout << setprecision(15) << ans << endl;
    return 0;
}