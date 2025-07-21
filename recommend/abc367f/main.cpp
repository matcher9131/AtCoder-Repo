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


int main() {
    ll n, nq;
    cin >> n >> nq;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<ll> b(n);
    for (ll i = 0; i < n; ++i) {
        cin >> b[i];
    }

    mt19937_64 gen(31);
    uniform_int_distribution<ll> rand(0, (1LL << 58) - 1);
    unordered_map<ll, ll> randMap;
    vector<ll> ha(n+1), hb(n+1);
    for (ll i = 0; i < n; ++i) {
        ll ra = randMap.contains(a[i]) ? randMap[a[i]] : (randMap[a[i]] = rand(gen));
        ha[i+1] = ha[i] + ra;
        ll rb = randMap.contains(b[i]) ? randMap[b[i]] : (randMap[b[i]] = rand(gen));
        hb[i+1] = hb[i] + rb;
    }

    while (nq--) {
        ll al, ar, bl, br;
        cin >> al >> ar >> bl >> br;
        --al;
        --bl;
        cout << (ha[ar] - ha[al] == hb[br] - hb[bl] ? "Yes" : "No") << endl;
    }

    return 0;
}