#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

bool isPalindrome(string &s) {
    ll n = s.size();
    for (ll i = 0; i < n/2; ++i) {
        if (s[i] != s[n-1-i]) return false;
    }
    return true;
}

int main() {
    ll n;
    cin >> n;
    vector<string> s(n);
    for (ll i = 0; i < n; ++i) {
        cin >> s[i];
    }

    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            if (i == j) continue;
            string t = s[i] + s[j];
            if (isPalindrome(t)) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
    return 0;
}