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
using namespace std;
using ll = long long;


int main() {
    int n;
    cin >> n;
    vector<tuple<int, int, ll>> w(n);
    vector<ll> s(n);
    for (int i = 0; i < n; ++i) {
        int d, c;
        ll s;
        cin >> d >> c >> s;
        w[i] = make_tuple(d, c, s);
    }
    sort(w.begin(), w.end());

    vector<vector<ll>> dp(n + 1, vector<ll>(5001));
    for (int i = 0; i < n; ++i) {
        auto [d, c, s] = w[i];
        for (int j = 0; j < 5000; ++j) {
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            if (j + c <= d && j + c <= 5000) dp[i + 1][j + c] = max(dp[i + 1][j + c], dp[i][j] + s);
        }
    }

    cout << *max_element(dp[n].begin(), dp[n].end()) << endl;

    return 0;
}