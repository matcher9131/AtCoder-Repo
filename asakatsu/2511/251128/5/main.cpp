#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/math>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

constexpr ll B = 27;

int main() {
    ll n;
    cin >> n;
    string t;
    cin >> t;

    vector<ll> mod{ 998244353, 1000000007, 1000000087 };
    ll m = mod.size();
    vector<ll> hash1(m), hash2(m);
    for (ll i = 0; i < n; ++i) {
        for (ll k = 0; k < m; ++k) {
            hash1[k] = (B * hash1[k] + (t[2*n-1-i] - 'a')) % mod[k];
            hash2[k] = (B * hash2[k] + (t[i] - 'a')) % mod[k];
        }
    }

    vector<vector<ll>> powB(n, vector<ll>(m));
    for (ll k = 0; k < m; ++k) {
        powB[0][k] = 1;
    };
    for (ll i = 1; i < n; ++i) {
        for (ll k = 0; k < m; ++k) {
            powB[i][k] = powB[i-1][k] * B % mod[k];
        }
    }
    
    for (ll i = 0; i < n; ++i) {
        if (hash1 == hash2) {
            cout << t.substr(0, i) << t.substr(n+i, n-i) << endl;
            cout << i << endl;
            return 0;
        }

        for (ll k = 0; k < m; ++k) {
            hash1[k] -= (t[n+i] - 'a') * powB[i][k];
            hash1[k] += (t[i] - 'a') * powB[i][k];
            hash1[k] %= mod[k];
            if (hash1[k] < 0) hash1[k] += mod[k];

            hash2[k] -= (t[i] - 'a') * powB[n-1][k];
            hash2[k] *= B;
            hash2[k] += (t[n+i] - 'a');
            hash2[k] %= mod[k];
            if (hash2[k] < 0) hash2[k] += mod[k];
        }
    }

    cout << -1 << endl;

    return 0;
}