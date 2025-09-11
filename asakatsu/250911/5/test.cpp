#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

ll comb(ll n, ll r) {
    ll ans = 1;
    for (ll i = 1; i <= n; ++i) {
        ans *= i;
    }
    for (ll i = 1; i <= r; ++i) {
        ans /= i;
    }
    for (ll i = 1; i <= n-r; ++i) {
        ans /= i;
    }
    return ans;
}

string nbase(ll x, ll n, ll length) {
    string ans;
    for (ll i = 0; i < length; ++i) {
        ans += (char)(x%n + '0');
        x /= n;
    }
    return ans;
}

int main() {
    ll n, k, l;
    cin >> n >> k >> l;
    bool shows = true;
    
    ll ans = 0;
    for (ll i = 0; i < pow(l, n); ++i) {
        string s = nbase(i, l, n);
        set<string> st;
        vector<bool> p;
        for (ll i = 0; i < n-k; ++i) {
            p.push_back(false);
        }
        for (ll i = 0; i < k; ++i) {
            p.push_back(true);
        }
        do {
            string t;
            for (ll i = 0; i < n; ++i) {
                if (p[i]) t += s[i];
            }
            st.insert(t);
        } while (next_permutation(p.begin(), p.end()));
        
        if ((ll)st.size() == comb(n, k)) {
            ++ans;
            if (shows) cout << s << endl;
        }
    }

    cout << ans << endl;

    return 0;
}