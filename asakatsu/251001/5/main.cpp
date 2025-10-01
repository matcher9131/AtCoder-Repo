#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

bool isPalindrome(string &s) {
    ll n = s.size();
    for (ll i = 0; i < n/2; ++i) {
        if (s[i] != s[n-1-i]) return false;
    }
    return true;
}

int main() {
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    auto isPalindrome = [&](string &s) {
        ll n = s.size();
        if (n < k) return false;
        for (ll i = 0; i < n/2; ++i) {
            if (s[i] != s[n-1-i]) return false;
        }
        return true;
    };

    vector<unordered_map<string, mint>> dp(n+1);
    dp[0][""] = 1;
    for (ll i = 0; i < n; ++i) {
        if (s[i] != 'B') {
            for (const auto &[t, c] : dp[i]) {
                string nt = (ll)t.size() < k ? t + 'A' : t.substr(1) + 'A';
                if (!isPalindrome(nt)) dp[i+1][nt] += c;
            }
        }
        if (s[i] != 'A') {
            for (const auto &[t, c] : dp[i]) {
                string nt = (ll)t.size() < k ? t + 'B' : t.substr(1) + 'B';
                if (!isPalindrome(nt)) dp[i+1][nt] += c;
            }
        }
    }

    mint ans = 0;
    for (const auto &[_, c] : dp[n]) {
        ans += c;
    }
    cout << ans.val() << endl;
    
    return 0;
}