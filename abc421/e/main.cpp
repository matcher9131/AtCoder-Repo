#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    vector<double> a(6);
    for (ll i = 0; i < 6; ++i) {
        cin >> a[i];
    }

    auto getScore = [&](vector<ll> &dist) -> double {
        map<double, ll> m;
        for (ll i = 0; i < 6; ++i) {
            m[a[i]] += dist[i];
        }
        double res = 0;
        for (const auto &[val, sum] : m) {
            res = max(res, val * sum);
        }
        return res;
    };

    vector<map<vector<ll>, double>> dp(3);
    function<double(ll, vector<ll>&)> dfs = [&](ll i, vector<ll> &s) -> double {
        if (dp[i].contains(s)) return dp[i][s];

        if (i == 0) {
            ll rest = 5 - accumulate(s.begin(), s.end(), 0LL);
            if (rest == 0) {
                return dp[i][s] = getScore(s);
            } else {
                for (ll p = 0; p < pow(6, rest); ++p) {
                    vector<ll> sp = s;
                    ll pp = p;
                    for (ll j = 0; j < rest; ++j) {
                        ++sp[pp % 6];
                        pp /= 6;
                    }
                    dp[i][s] += getScore(sp);
                }
                dp[i][s] /= pow(6, rest);
                return dp[i][s];
            }
        } else {
            ll rest = 5 - accumulate(s.begin(), s.end(), 0LL);
            if (rest == 0) {
                return dp[i][s] = dfs(i-1, s);
            } else {
                for (ll p = 0; p < pow(6, rest); ++p) {
                    ll pp = p;
                    vector<ll> dice;
                    for (ll j = 0; j < rest; ++j) {
                        dice.push_back(pp % 6);
                        pp /= 6;
                    }
                    double stMax = 0;
                    for (ll bit = 0; bit < 1LL << rest; ++bit) {
                        vector<ll> st = s;
                        for (ll j = 0; j < rest; ++j) {
                            if (bit & (1LL << j)) ++st[dice[j]];
                        }
                        stMax = max(stMax, dfs(i-1, st));
                    }
                    dp[i][s] += stMax;
                }
                dp[i][s] /= pow(6, rest);
                return dp[i][s];
            }
        }
    };
    vector<ll> emp(6);
    cout << setprecision(15) << dfs(2, emp) << endl;

    return 0;
}