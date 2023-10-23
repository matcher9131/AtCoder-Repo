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

constexpr ll INF = 9e18;

ll powLL(ll base, int exp) {
    ll ans = 1;
    for (int i = 0; i < exp; ++i) {
        ans *= base;
    }
    return ans;
}

int main() {
    string s;
    ll m;
    cin >> s >> m;

    if (s.size() == 1) {
        cout << (s[0] - '0' <= m ? 1 : 0) << endl;
        return 0;
    }

    vector<int> a(s.size());
    for (int i = 0; i < s.size(); ++i) {
        a[i] = s[i] - '0';
    }
    int d = *max_element(a.begin(), a.end());

    auto sToNum = [&](ll base) {
        double t = 0;
        for (int i = 0; i < s.size(); ++i) {
            t += a[s.size() - 1 - i] * pow(base, i);
        }
        if (!isfinite(t) || t > INF) return INF;
        ll r = 0;
        for (int i = 0; i < s.size(); ++i) {
            r += a[s.size() - 1 - i] * powLL(base, i);
        }
        return r;
    };

    if (sToNum(d + 1) > m) {
        cout << 0 << endl;
        return 0;
    }

    auto isOK = [&](ll base) {
       return sToNum(base) <= m;
    };

    function<ll()> binary_search = [&]() {
        ll ng = m + 1;
        ll ok = d + 1;

        while (abs(ok - ng) > 1) {
            ll mid = (ok + ng) / 2;
            if (isOK(mid)) ok = mid;
            else ng = mid;
        }
        return ok;
    };

    ll ans = binary_search() - d;
    cout << ans << endl;

    return 0;
}