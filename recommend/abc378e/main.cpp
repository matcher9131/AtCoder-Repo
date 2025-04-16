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
#include <atcoder/fenwicktree>
using namespace std;
using ll = long long;


int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<ll> s(n+1);
    for (int i = 0; i < n; ++i) {
        s[i+1] = (s[i] + a[i]) % m;
    }

    atcoder::fenwick_tree<ll> fw(m);
    // sの各項において自分より右にあって自分より小さい数の個数
    vector<ll> less(n+1);
    for (int i = n; i >= 0; --i) {
        less[i] = fw.sum(0, s[i]);
        fw.add(s[i], 1);
    }

    vector<ll> ss(n+1);
    for (int i = 1; i <= n; ++i) {
        ss[i] = ss[i-1] + s[i];
    }

    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += -(n - i + 1) * s[i-1] + ss[n] - ss[i-1] + m * less[i-1];
    }

    cout << ans << endl;
    return 0;
}