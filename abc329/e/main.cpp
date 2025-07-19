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
    ll n, m;
    string s, t;
    cin >> n >> m >> s >> t;

    auto canRestore = [&](ll si) -> bool {
        if (si + m > n) return false;
        for (ll i = 0; i < m; ++i) {
            if (s[si + i] != '#' && s[si + i] != t[i]) return false;
        }
        return true;
    };

    queue<ll> que;
    for (ll i = 0; i < n; ++i) {
        if (canRestore(i)) que.push(i);
    }

    vector<bool> visited(n);
    while (!que.empty()) {
        int si = que.front();
        que.pop();
        for (ll i = 0; i < m; ++i) {
            s[si + i] = '#';
        }
        visited[si] = true;
        for (ll i = 1; i < m; ++i) {
            if (si + i < n && !visited[si + i] && canRestore(si + i)) que.push(si + i);
            if (si - i >= 0 && !visited[si - i] && canRestore(si - i)) que.push(si - i);
        }
    }

    cout << (all_of(s.begin(), s.end(), [](char c) { return c == '#'; }) ? "Yes" : "No") << endl;

    return 0;
}