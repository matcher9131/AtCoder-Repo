#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    string s;
    cin >> s;

    // dp[i][j]: i文字目まで見て状態jになる文字列の個数の期待値
    // j=0: 大文字を含まない
    // j=1-26: j種類の大文字をちょうと1つずつ含む
    // j=27: 同じ大文字を2つ含み、それより後に小文字を含まない
    // j=28: 同じ大文字を2つ含み、それより後に小文字を含み、それより後に大文字を含まない
    vector<mint> dp(29);
    dp[0] = 1;
    unordered_set<char> upper;

    for (const char c : s) {
        vector<mint> ndp(29);
        if ('a' <= c && c <= 'z') {
            ndp[0] += dp[0];
            for (ll j = 1; j <= 26; ++j) {
                ndp[j] += dp[j];
            }
            ndp[28] += dp[27];
            ndp[28] += dp[28];
        } else if ('A' <= c && c <= 'Z') {
            ndp[1] += dp[0];
            if (upper.contains(c)) {
                for (ll j = 1; j <= 26; ++j) {
                    ndp[27] += dp[j];
                }
            } else {
                ll numSurelyContained = upper.size();
                if (numSurelyContained < 26) {
                    // dp[j]には(j - numSurelyContained)個の不確定の大文字が含まれる
                    // cがその不確定の大文字のいずれかであるとき確率(j - numSurelyContained) / (26 - numSurelyContained)でdp[27]へ遷移
                    // そうではないとき、確率 (26 - j) / (26 - numSurelyContained)でdp[j+1]へ遷移
                    for (ll j = 1; j <= 26; ++j) {
                        ndp[27] += dp[j] * (j - numSurelyContained) / (26 - numSurelyContained);
                        ndp[j+1] += dp[j] * (26 - j) / (26 - numSurelyContained);
                    }
                } else {
                    // 確実に含まれる大文字が26種類ある
                    ndp[27] += dp[26];
                }
            }
            upper.insert(c);
            ndp[27] += dp[27];
        } else {
            // ?が小文字
            ndp[0] += 26 * dp[0];
            for (ll j = 1; j <= 26; ++j) {
                ndp[j] += 26 * dp[j];
            }
            ndp[28] += 26 * dp[27];
            ndp[28] += 26 * dp[28];
            // ?が大文字
            for (ll j = 0; j <= 26; ++j) {
                // 26-j種類は新たな大文字、j種類は2個目の大文字
                ndp[j+1] += (26 - j) * dp[j];
                ndp[27] += j * dp[j];
            }
            ndp[27] += 26 * dp[27];
        }
        swap(dp, ndp);
    }

    cout << accumulate(dp.begin(), dp.end(), (mint)0).val() << endl;

    return 0;
}