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

    // map<vector<ll>, double> sc;
    auto getScore = [&](vector<ll> &dist) -> double {
        // if (sc.contains(dist)) return sc[dist];
        double res = 0;
        for (ll i = 0; i < 6; ++i) {
            res = max(res, dist[i] * a[i]);
        }
        // return sc[dist] = res;
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
                for (ll dicePattern = 0; dicePattern < pow(6, rest); ++dicePattern) {
                    vector<ll> sp = s;
                    ll pp = dicePattern;
                    for (ll j = 0; j < rest; ++j) {
                        ++sp[pp % 6];
                        pp /= 6;
                    }
                    dp[i][s] += getScore(sp) / pow(6, rest);
                }
                return dp[i][s];
            }
        } else {
            ll rest = 5 - accumulate(s.begin(), s.end(), 0LL);
            for (ll dicePattern = 0; dicePattern < pow(6, rest); ++dicePattern) {
                ll pp = dicePattern;
                vector<ll> dice(rest);
                for (ll j = 0; j < rest; ++j) {
                    dice.push_back(pp % 6);
                    pp /= 6;
                }
                double pMax = 0;
                for (ll bit = 0; bit < 1LL << rest; ++bit) {
                    vector<ll> st = s;
                    for (ll j = 0; j < rest; ++j) {
                        if (bit & (1LL << j)) ++st[dice[j]];
                    }
                    pMax = max(pMax, dfs(i-1, st));
                }
                dp[i][s] += pMax / pow(6, rest);
            }
            return dp[i][s];
        }
    };
    vector<ll> emp(6);
    cout << setprecision(15) << dfs(2, emp) << endl;

    return 0;
}