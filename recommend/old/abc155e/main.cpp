#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    s += '0';
    int n = s.size();
    vector<int> a(n);
    for (ll i = 0; i < n; ++i) {
        a[i] = s[i] - '0';
    }

    ll ans = 0;
    ll i = 0;
    while (i < n) {
        if (a[i] < 5 || (a[i] == 5 && a[i+1] < 5)) {
            ans += a[i];
            ++i;
        } else {
            ans += 10 - a[i];
            a[i] = 0;
            ++i;
            while (a[i] == 9) {
                a[i] = 0;
                ++i;
            }
            ++a[i];
        }
    }
    
    cout << ans << endl;
    
    return 0;
}