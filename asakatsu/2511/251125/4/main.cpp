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
    ll n, s;
    cin >> n >> s;
    vector<ll> a(n), b(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }

    vector<vector<ll>> dp(n+1, vector<ll>(s+1, -1));
    dp[0][0] = 0;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < s; ++j) {
            if (dp[i][j] == -1) continue;
            if (j+a[i] <= s) dp[i+1][j+a[i]] = j;
            if (j+b[i] <= s) dp[i+1][j+b[i]] = j;
        }
    }
    
    if (dp[n][s] == -1) {
        cout << "No" << endl;
        return 0;
    }

    stack<char> st;
    ll prev = s;
    for (ll i = n - 1; i >= 0; --i) {
        st.push(prev - dp[i+1][prev] == a[i] ? 'H' : 'T');
        prev = dp[i+1][prev];
    }
    cout << "Yes" << endl;
    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }
    cout << endl;

    return 0;
}