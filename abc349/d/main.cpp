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
    ll left, right;
    cin >> left >> right;

    vector<pair<ll, ll>> seg;
    // l = j * 2^i
    function<void(ll,ll)> dfsr = [&](ll l, ll r) -> void {
        if (l == r) return;

        int i = bit_width((ull)(r - l));
        while (i > 0) {
            if (1LL << i <= r - l) break;
            --i;
        }
        ll j = l / (1LL << i);
        ll nl = (1LL << i) * (j+1);
        seg.emplace_back(l, nl);
        dfsr(nl, r);
    };
    // r = (j+1) * 2^i
    function<void(ll,ll)> dfsl = [&](ll l, ll r) -> void {
        if (l == r) return;

        int i = bit_width((ull)(r - l));
        while (i > 0) {
            if (1LL << i <= r - l) break;
            --i;
        }
        ll j = r / (1LL << i) - 1;
        ll nr = (1LL << i) * j;
        seg.emplace_back(nr, r);
        dfsl(l, nr);
    };

    ll mid;
    for (int i = bit_width((ull)right); i >= 0; --i) {
        mid = right / (1LL << i) * (1LL << i);
        if (mid >= left) break;
    }
    dfsl(left, mid);
    dfsr(mid, right);
    sort(seg.begin(), seg.end());
    
    cout << seg.size() << endl;
    for (const auto &[l, r] : seg) {
        cout << l << " " << r << endl;
    }

    return 0;
}