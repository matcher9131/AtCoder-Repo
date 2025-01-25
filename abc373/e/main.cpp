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
    ll k;
    cin >> n >> m >> k;
    ll rest = k;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b[i] = a[i];
        rest -= a[i];
    }
    sort(b.begin(), b.end());
    // s(r) - s(l)が[l, r)におけるb[i]の和
    vector<ll> s(n + 1);
    for (int i = 0; i < n; ++i) {
        s[i + 1] = s[i] + b[i];
    }

    for (int i = 0; i < n; ++i) {
        int rank = lower_bound(b.begin(), b.end(), a[i] + 1) - b.begin() - 1;

        auto isOK = [&](ll x) -> bool {
            if (rank >= n - m) {
                // 元々上位m人に入っている→上位m+1人のうち自分以外に上回られると落ちる
                int l = n - m - 1;
                int r = lower_bound(b.begin(), b.end(), a[i] + x + 1) - b.begin();
                if (rank == r) {
                    // [l, r)に元の自分が入らない
                    ll nov = (r - l) * (a[i] + x + 1) - (s[r] - s[l]);
                    return nov + x > rest;
                } else {
                    // [l, r)に元の自分が入る
                    ll nov = (r - l - 1) * (a[i] + x + 1) - (s[r] - s[l] - a[i]);
                    return nov + x > rest;
                }
            } else {
                // 元々上位m人に入っていない→上位m人に上回られると落ちる
                int l = n - m;
                int r = lower_bound(b.begin(), b.end(), a[i] + x + 1) - b.begin();
                if (r <= l) return false;
                // [l, r)に元の自分が入ることはない
                ll nov = (r - l) * (a[i] + x + 1) - (s[r] - s[l]);
                return nov + x > rest;
            }
        };

        auto search = [&]() -> ll {
            ll ok = rest + 1;
            ll ng = -1;

            while (abs(ok - ng) > 1) {
                ll mid = (ok + ng) / 2;
                if (isOK(mid)) ok = mid;
                else ng = mid;
            }
            return ok;
        };

        ll ans = n == m ? 0 : search();
        cout << (ans == rest + 1 ? -1 : ans) << " \n"[i == n - 1];
    }

    return 0;
}