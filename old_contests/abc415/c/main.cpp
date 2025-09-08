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

void solve() {
    ll n;
    string s;
    cin >> n >> s;
    if (s[(1LL << n) - 2] == '1') {
        cout << "No" << endl;
        return;
    }

    vector<int> memo(s.size(), -1);
    function<bool(ll)> dfs = [&](ll state) -> bool {
        if (state == (1LL << n) - 1) return true;
        if (memo[state] != -1) return memo[state] == 1;
        for (ll i = 0; i < n; ++i) {
            if (state & (1LL << i)) continue;
            ll newState = state | (1LL << i);
            if (s[newState-1] == '1') continue;
            memo[newState] = dfs(newState) ? 1 : 0;
            if (memo[newState] == 1) return true;
        }
        return false;
    };
    cout << (dfs(0) ? "Yes" : "No") << endl;
}

int main() {
    ll t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}