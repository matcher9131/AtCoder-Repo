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
    ll n, k;
    cin >> n >> k;
    map<ll, ll> x, y;
    for (ll i = 0; i < n; ++i) {
        ll xi, yi;
        cin >> xi >> yi;
        ++x[xi];
        ++y[yi];
    }
    map<ll, tuple<ll, ll, ll, ll>> mx, my;
    {
        ll prev = x.begin()->first, prevNum = 0, prevOp = 0;
        for (auto it = x.begin(); it != x.end(); ++it) {
            ll op = prevOp + prevNum * abs(it->first - prev);
            get<0>(mx[it->first]) = op;
            prevOp = op;
            ll num = prevNum + it->second;
            get<1>(mx[it->first]) = num;
            prevNum = num;
            prev = it->first;
        }
    }
    {
        ll prev = x.rbegin()->first, prevNum = 0, prevOp = 0;
        for (auto it = x.rbegin(); it != x.rend(); ++it) {
            ll op = prevOp + prevNum * abs(it->first - prev);
            get<2>(mx[it->first]) = op;
            prevOp = op;
            ll num = prevNum + it->second;
            get<3>(mx[it->first]) = num;
            prevNum = num;
            prev = it->first;
        }
    }
    {
        ll prev = y.begin()->first, prevNum = 0, prevOp = 0;
        for (auto it = y.begin(); it != y.end(); ++it) {
            ll op = prevOp + prevNum * abs(it->first - prev);
            get<0>(my[it->first]) = op;
            prevOp = op;
            ll num = prevNum + it->second;
            get<1>(my[it->first]) = num;
            prevNum = num;
            prev = it->first;
        }
    }
    {
        ll prev = y.rbegin()->first, prevNum = 0, prevOp = 0;
        for (auto it = y.rbegin(); it != y.rend(); ++it) {
            ll op = prevOp + prevNum * abs(it->first - prev);
            get<2>(my[it->first]) = op;
            prevOp = op;
            ll num = prevNum + it->second;
            get<3>(my[it->first]) = num;
            prevNum = num;
            prev = it->first;
        }
    }

    auto numOp = [&](map<ll, tuple<ll, ll, ll, ll>> &m, ll size) -> ll {
        ll ans = 1e16;
        for (auto left = m.begin(); left != m.end(); ++left) {
            ll x0 = left->first;
            auto right = m.lower_bound(x0 + size);
            if (right == m.end()) {
                ans = min(ans, get<0>(left->second));
            } else {
                ll op = get<0>(left->second) + get<2>(right->second) + (right->first - x0 - size) * min(get<1>(left->second), get<3>(right->second));
                ans = min(ans, op);
            }
        }
        for (auto right = m.rbegin(); right != m.rend(); ++right) {
            ll x1 = right->first;
            auto left = m.lower_bound(x1 - size);
            if (left != m.begin() && x1 - left->first < size) --left;
            if (left == m.begin() && x1 - left->first < size) {
                ans = min(ans, get<2>(right->second));
            } else {
                ll op = get<0>(left->second) + get<2>(right->second) + (x1 - left->first - size) * min(get<1>(left->second), get<3>(right->second));
                ans = min(ans, op);
            }
        }
        return ans;
    };

    auto isOK = [&](ll size) -> bool {
        ll opX = numOp(mx, size);
        ll opY = numOp(my, size);
        return opX + opY <= k;
    };

    ll ok = 1e9;
    ll ng = -1;
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if (isOK(mid)) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;
    return 0;
}