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
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll = long long;

void addIfNotExist(vector<int>& v, int x) {
    if (find(v.begin(), v.end(), x) == v.end()) v.push_back(x);
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        int ai;
        cin >> ai;
        a[i] = ai % 200;
    }

    // dp[i][k] := aの先頭i個からいくつか選んだ和がk(mod 200)になるパターンの総数
    vector<vector<ll>> dp(n + 1, vector<ll>(200));
    // pre[i][k][] := dp[i][k]がdp[i-1][k']から更新されるとき、k'を記録（配列で保持）
    vector<vector<vector<int>>> pre(n + 1, vector<vector<int>>(200, vector<int>()));
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < 200; ++k) {
            if (dp[i][k] > 0) {
                if (dp[i + 1][k] < 2) {
                    dp[i + 1][k] += dp[i][k];
                    addIfNotExist(pre[i + 1][k], k);
                }
                int newK = (k + a[i]) % 200;
                if (dp[i + 1][newK] < 2) {
                    dp[i + 1][newK] += dp[i][k];
                    addIfNotExist(pre[i + 1][newK], k);
                }
            }
        }
    }

    for (int k = 0; k < 200; ++k) {
        if (dp[n][k] >= 2) {
            vector<int> b;
            vector<int> c;
            bool switched = false;
            int bk = k, ck = k;
            for (int i = n; i > 0; --i) {
                if (!switched) {
                    if (pre[i][bk].size() >= 2) {
                        int preBk = pre[i][bk][0];
                        int preCk = pre[i][ck][1];
                        if (preBk != bk) b.push_back(i);
                        if (preCk != ck) c.push_back(i);
                        bk = preBk;
                        ck = preCk;
                        switched = true;
                        continue;
                    } else if (pre[i][bk].size() == 1 && a[i - 1] == 0) {
                        // preBk == preCk == bk == ck
                        b.push_back(i);
                        switched = true;
                        continue;
                    }
                } 
                int preBk = pre[i][bk][0];
                int preCk = pre[i][ck][0];
                if (preBk != bk || a[i - 1] == 0) b.push_back(i);
                if (preCk != ck || a[i - 1] == 0) c.push_back(i);
                bk = preBk;
                ck = preCk;
            }
            if (b.empty() || c.empty()) continue;
            reverse(b.begin(), b.end());
            reverse(c.begin(), c.end());
            cout << "Yes" << endl;
            cout << b.size() << " " << b[0];
            for (int i = 1; i < b.size(); ++i) {
                cout << " " << b[i];
            }
            cout << endl;
            cout << c.size() << " " << c[0];
            for (int i = 1; i < c.size(); ++i) {
                cout << " " << c[i];
            }
            cout << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    //
    //for (int i = 0; i < 200; ++i) {
        //cout << dp[i][0] << endl;
        //cout << a[i] << endl;
    //}
    //

    return 0;
}