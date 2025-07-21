#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <climits>
#include <cfloat>
#include <utility>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <numeric>
#include <functional>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint1000000007;


int main() {
    ll n;
    cin >> n;

    // dp[i][j]: i文字目(0-indexed)までで末尾の3文字がjであるような条件を満たす文字列の個数
    vector<unordered_map<string, mint>> dp(n);
    string sample = "ACGT";
    for (ll i = 0; i < 4; ++i) {
        for (ll j = 0; j < 4; ++j) {
            for (ll k = 0; k < 4; ++k) {
                string s({ sample[i], sample[j], sample[k] });
                if (s != "AGC" && s != "GAC" && s != "ACG") dp[2][s] = 1;
            }
        }
    }

    
    for (ll i = 3; i < n; ++i) {
        for (const auto &[s, c] : dp[i-1]) {
            for (ll j = 0; j < 4; ++j) {
                string t = s + sample[j];
                string nt = t.substr(1);
                if (
                    nt != "ACG"
                    && nt != "AGC"
                    && nt != "GAC"
                    && t[0] + t.substr(2) != "AGC"
                    && t.substr(0, 2) + t[3] != "AGC"
                ) {
                    dp[i][nt] += c;
                }
            }
        }
    }

    mint ans = 0;
    for (const auto &[_, c] : dp[n-1]) {
        ans += c;
    }
    cout << ans.val() << endl;

    return 0;
}