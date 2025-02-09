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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    auto isOK = [&](ll x) -> bool {
        vector<ll> dif(n);
        for (int i = 0; i < n; ++i) {
            for (int bit = 31; bit >= 0; --bit) {
                ll mask = (1LL << (bit + 1)) - 1LL;
                ll d = (x & mask) - (a[i] & mask);
                if (d > 0) {
                    dif[i] = d;
                    break;
                }
            }
        }
        sort(dif.begin(), dif.end());
        ll sum = accumulate(dif.begin(), dif.begin() + k, 0LL);
        return sum <= m;
    };

    // ll ng = 1LL << 31;
    // ll ok = 0;

    // while (ng - ok > 1) {
    //     ll mid = (ok + ng) / 2;
    //     if (isOK(mid)) ok = mid;
    //     else ng = mid;
    // }

    ll ans = 0;
    for (int i = 31; i >= 0; --i) {
        if (isOK(ans + (1LL << i))) ans += 1LL << i;
    }

    cout << ans << endl;

    return 0;
}