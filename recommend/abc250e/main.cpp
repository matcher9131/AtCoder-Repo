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
#include <random>
using namespace std;
using ll = long long;

constexpr ll BASE = 31;

int main() {
    mt19937_64 gen(31);
    uniform_int_distribution<ll> rnd(0, (1LL << 61) - 1);

    ll n;
    cin >> n;
    unordered_set<ll> a, b;
    unordered_map<ll, ll> table;
    vector<ll> ha(n+1), hb(n+1);
    for (ll i = 1; i <= n; ++i) {
        ll ai;
        cin >> ai;
        if (a.contains(ai)) {
            ha[i] = ha[i-1];
        } else {
            a.insert(ai);
            if (!table.contains(ai)) {
                table[ai] = rnd(gen);
            }
            ha[i] = ha[i-1] ^ table[ai];
        }
    }
    for (ll i = 1; i <= n; ++i) {
        ll bi;
        cin >> bi;
        if (b.contains(bi)) {
            hb[i] = hb[i-1];
        } else {
            b.insert(bi);
            if (!table.contains(bi)) {
                table[bi] = rnd(gen);
            }
            hb[i] = hb[i-1] ^ table[bi];
        }
    }

    ll nq;
    cin >> nq;
    while (nq--) {
        ll x, y;
        cin >> x >> y;
        cout << (ha[x] == hb[y] ? "Yes" : "No") << endl;
    }

    return 0;
}