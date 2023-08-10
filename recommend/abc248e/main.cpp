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
using namespace std;
using ll = long long;

pair<ll, ll> normalize(ll x, ll y) {
    if (x == 0) {
        if (y == 0) return make_pair(0, 0);
        return make_pair(0, 1);
    } else if (y == 0) {
        return make_pair(1, 0);
    } else {
        ll g = gcd(x, y);
        if (x < 0) {
            return make_pair(-x / g, -y / g);
        } else {
            return make_pair(x / g, y / g);
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    if (k == 1) {
        cout << "Infinity" << endl;
        return 0;
    }
    vector<ll> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    vector<int> count(n + 1);
    vector<pair<ll, ll>> d(n - 1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            d[j - (j > i ? 1 : 0)] = normalize(x[j] - x[i], y[j] - y[i]);
        }
        sort(d.begin(), d.end());

        ll prevX = d[0].first, prevY = d[0].second;
        int sj = 0;
        for (int j = 0; j < n - 1; ++j) {
            auto [x, y] = d[j];
            if (x != prevX || y != prevY) {
                // t本の正規化ベクトルが一致するとき、同じ直線上にt+1個の点が存在する
                if (j - sj + 1 >= k) ++count[j - sj + 1];
                prevX = x;
                prevY = y;
                sj = j;
            }
        }
        if (n - 1 - sj + 1 >= k) ++count[n - 1 - sj + 1];
    }

    int answer = 0;
    for (int i = 1; i <= n; ++i) {
        answer += count[i] / i;
    }

    cout << answer << endl;

    return 0;
}