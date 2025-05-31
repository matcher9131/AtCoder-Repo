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
#include <atcoder/string>
using namespace std;
using ll = long long;

bool contains(const string &s, const string &t) {
    int n = s.size(), m = t.size();
    vector<int> za = atcoder::z_algorithm(t + "#" + s);
    for (int i = m + 1; i < n + m + 1; ++i) {
        if (za[i] == m) return true;
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    for (auto it = s.begin(); it != s.end(); ) {
        bool contained = false;
        for (auto it2 = s.begin(); it2 != s.end(); ++it2) {
            if (it == it2) continue;
            if (contains(*it2, *it)) {
                contained = true;
                break;
            }
        }
        if (contained) {
            it = s.erase(it);
        } else {
            ++it;
        }
    }

    n = s.size();
    vector<vector<int>> d(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        int s1 = s[i].size();
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            int s2 = s[j].size(); 
            vector<int> za = atcoder::z_algorithm(s[j] + "_" + s[i]);
            d[i][j] = s[j].size();
            for (int k = 0; k < s1; ++k) {
                if (za[s2 + 1 + k] == s1 - k) {
                    d[i][j] = s2 - (s1 - k);
                    break;
                }
            }
        }
    }

    // dp[i][j]: 訪問済み頂点の集合がi、最後に訪れた頂点がjとなる巡回における最小の距離
    vector<vector<int>> dp(1 << n, vector<int>(n, 1e8));
    for (int i = 0; i < n; ++i) {
        dp[1 << i][i] = s[i].size();
    }
    for (int bit = 1; bit < (1 << n) - 1; ++bit) {
        for (int i = 0; i < n; ++i) {
            if (~bit & (1 << i)) continue;
            for (int j = 0; j < n; ++j) {
                if (bit & (1 << j)) continue;
                dp[bit | (1 << j)][j] = min(dp[bit | (1 << j)][j], dp[bit][i] + d[i][j]);
            }
        }
    }

    cout << *min_element(dp[(1 << n) - 1].begin(), dp[(1 << n) - 1].end()) << endl;
    return 0;
}