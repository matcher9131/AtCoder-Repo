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
using ull = unsigned long long;

int main() {
    int n, k;
    ll p;
    cin >> n >> k >> p;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int m1 = n / 2;
    int m2 = n - m1;
    vector<vector<ll>> former(m1 + 1), latter(m2 + 1);
    for (int bit = 0; bit < (1 << m1); ++bit) {
        int c = 0;
        ll sum = 0;
        for (int i = 0; i < m1; ++i) {
            if (bit & (1 << i)) {
                ++c;
                sum += a[i];
            }
        }
        former[c].push_back(sum);
    }
    for (int bit = 0; bit < (1 << m2); ++bit) {
        int c = 0;
        ll sum = 0;
        for (int i = 0; i < m2; ++i) {
            if (bit & (1 << i)) {
                ++c;
                sum += a[m1 + i];
            }
        }
        latter[c].push_back(sum);
    }
    for (int i = 0; i <= m1; ++i) {
        sort(former[i].begin(), former[i].end());
    }
    for (int i = 0; i <= m2; ++i) {
        sort(latter[i].begin(), latter[i].end());
    }

    ll ans = 0;
    for (int i = 0; i <= m1; ++i) {
        int j = k - i;
        if (j < 0 || j > m2) continue;
        for (const ll f : former[i]) {
            if (f > p) continue;
            ans += upper_bound(latter[j].begin(), latter[j].end(), p - f) - latter[j].begin();
        }
    }

    cout << ans << endl;

    return 0;
}