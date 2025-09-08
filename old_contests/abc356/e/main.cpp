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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int m = 1e6 + 1;
    vector<int> c(m);
    for (const int ai : a) {
        ++c[ai];
    }
    for (int i = 0; i < m; ++i) {
        c[i+1] += c[i];
    }

    ll ans = 0;
    for (int i = 1; i < m; ++i) {
        int d = c[i] - c[i-1];
        for (int q = 1; i * q < m; ++q) {
            // iq <= x < i(q+1) のとき floor(x/i) = q を利用してまとめて加算
            ans += (ll)q * (c[min(m-1, i * (q+1) - 1)] - c[i * q - 1]) * d;
        }
        // 自身および自身と同じ数を選んでしまっているので調整
        ans -= (ll)d * (d+1) / 2;
    }

    cout << ans << endl;
    return 0;
}