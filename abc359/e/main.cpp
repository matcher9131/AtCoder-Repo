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
    vector<ll> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }

    // 壁の高さ, 壁番号, それより左を全て満たすのに必要な水の量
    stack<tuple<ll, int, ll>> s;
    vector<ll> ans(n);
    for (int i = 0; i < n; ++i) {
        while (!s.empty()) {
            auto [wh, wi, sum] = s.top();
            if (wh > h[i]) break;
            s.pop();
        }
        if (s.empty()) {
            ll newSum = h[i] * (i + 1);
            s.emplace(h[i], i, newSum);
            ans[i] = newSum + 1;
        } else {
            auto [_, wi, sum] = s.top();
            ll newSum = sum + (i - wi) * h[i];
            s.emplace(h[i], i, newSum);
            ans[i] = newSum + 1;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " \n"[i == n - 1];
    }

    return 0;
}