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
using namespace std;
using ll = long long;


int main() {
    string s;
    int q;
    cin >> s >> q;
    vector<ll> t(q), k(q);
    for (int i = 0; i < q; ++i) {
        cin >> t[i] >> k[i];
        --k[i];
    }

    for (int qi = 0; qi < q; ++qi) {
        ll ki = k[qi];
        ll c = 0;
        for (ll i = 0; i < min(t[qi], 64LL); ++i) {
            if (ki & 1LL) ++c;
            ki >>= 1;
        }

        if (s[ki] == 'B') c += 1;
        else if (s[ki] == 'C') c += 2;

        ll r = (t[qi] + c) % 3LL;
        cout << (r == 0LL ? 'A' : r == 1LL ? 'B' : 'C') << endl;
    }

    return 0;
}