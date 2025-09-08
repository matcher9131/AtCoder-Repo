#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll x, y, z;
    string s;
    cin >> x >> y >> z >> s;
    ll n = s.size();

    // dp[i][j]: i文字(1-indexed)入力して状態jになる最小の時間
    // j=0: CapsLock Off, i文字目を入力後にCapsLockキーをまだ押していない
    // j=1: CapsLock On, i文字目を入力後にCapsLockキーをまだ押していない
    // j=2: CapsLock Off, i文字目を入力後にCapsLockキーを押した
    // j=3: CapsLock On, i文字目を入力後にCapsLockキーを押した
    vector<vector<ll>> dp(n+1, vector<ll>(4, INF));
    dp[0][0] = 0;
    dp[0][3] = z;
    auto chMin = [&](ll i, ll j, ll val) -> void {
        dp[i][j] = min(dp[i][j], val);
    };

    for (ll i = 0; i < n; ++i) {
        if (dp[i][0] != INF) {
            chMin(i+1, 0, dp[i][0] + (s[i] == 'a' ? x : y));
            chMin(i, 3, dp[i][0] + z);
        }
        if (dp[i][1] != INF) {
            chMin(i+1, 1, dp[i][1] + (s[i] == 'A' ? x : y));
            chMin(i, 2, dp[i][1] + z);
        }
        if (dp[i][2] != INF) {
            chMin(i+1, 0, dp[i][2] + (s[i] == 'a' ? x : y));
        }
        if (dp[i][3] != INF) {
            chMin(i+1, 1, dp[i][3] + (s[i] == 'A' ? x : y));
        }
    }

    cout << *min_element(dp[n].begin(), dp[n].end()) << endl;
    return 0;
}