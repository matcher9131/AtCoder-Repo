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

int singleFactor(int x) {
    vector<pair<int, int>> dic;

    for (int p = 2; p * p <= x; ++p) {
        if (x % p != 0) continue;
        int e = 0;
        while (x % p == 0) {
            ++e;
            x /= p;
        }
        dic.emplace_back(p, e);
    }
    if (x > 1) {
        dic.emplace_back(x, 1);
    }

    int ans = 1;
    for (const auto& [p, e] : dic) {
        if (e % 2) ans *= p;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int m = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        m = max(m, a[i]);
    }

    vector<int> count(m + 1);
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) {
            ++count[0];
        } else {
            ++count[singleFactor(a[i])];
        }
    }

    ll ans = (ll)n * (n-1) / 2 - (ll)(n - count[0]) * (n - count[0] - 1) / 2;
    for (int i = 1; i < m + 1; ++i) {
        ans += (ll)count[i] * (count[i] - 1) / 2;
    }

    cout << ans << endl;

    return 0;
}