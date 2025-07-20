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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> s(n+1);
    for (int i = 0; i < n; ++i) {
        s[i+1] = (s[i] + a[i]) % m;
    }
    unordered_map<int, ll> count;
    for (int i = 0; i <= n; ++i) {
        ++count[s[i]];
    }

    ll ans = 0;
    for (const auto &[_, c] : count) {
        ans += c * (c-1) / 2;
    }

    cout << ans << endl;
    return 0;
}