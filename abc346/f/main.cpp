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

constexpr ll INF = 1e18;

int main() {
    ll n;
    string s, t;
    cin >> n >> s >> t;
    ll m = s.size();

    vector<vector<ll>> sci(26);
    for (int i = 0; i < m; ++i) {
        sci[s[i] - 'a'].push_back(i);
    }

    //f(s, n)のfrom文字目以降で（そこから数えて）k番目の文字chの位置
    auto sIndexOf = [&](ll from, int ch, ll k) {
        if (sci[ch].size() == 0) return INF;

        ll q = from / m, r = from % m;
        auto it = lower_bound(sci[ch].begin(), sci[ch].end(), r);
        k += it - sci[ch].begin();
        q += k / (ll)sci[ch].size();
        return q * m + sci[ch][k % (ll)sci[ch].size()];
    };

    auto isOk = [&](ll k) {
        if (k == 0) return true;
        ll index = 0;
        for (const char ch : t) {
            if (index >= n * m) return false;
            index = sIndexOf(index, ch - 'a', k - 1) + 1;
            if (index > n * m) return false;
        }
        return true;
    };

    ll ok = 0;
    ll ng = m * n / (int)t.size() + 1;

    while (ng - ok > 1) {
        ll mid = (ok + ng) / 2;
        if (isOk(mid)) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;
    return 0;
}