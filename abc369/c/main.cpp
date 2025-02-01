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

constexpr ll INF= 1e16;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ll ans = n;
    int left = 0;
    ll d = INF;
    for (int i = 1; i <= n; ++i) {
        if (d == INF) {
            d = a[i] - a[i - 1];
        } else if (i == n || a[i] - a[i - 1] != d) {
            // [left, i)が等差数列
            ll m = i - left;
            // 単項でないものの数を数える
            ans += m * (m - 1) / 2;
            // 一つ前の項から再開
            --i;
            left = i;
            d = INF;
        }
    }

    cout << ans << endl;

    return 0;
}