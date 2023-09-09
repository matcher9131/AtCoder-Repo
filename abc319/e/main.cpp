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
    int n;
    ll x, y;
    cin >> n >> x >> y;
    vector<int> p(n - 1);
    vector<ll> t(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> p[i] >> t[i];
    }
    int cq;
    cin >> cq;
    vector<ll> q(cq);
    for (int i = 0; i < cq; ++i) {
        cin >> q[i];
    }

    vector<ll> s(840);
    for (int k = 0; k < 840; ++k) {
        ll si = k;
        for (int i = 0; i < n - 1; ++i) {
            si = (si + p[i] - 1LL) / p[i] * p[i] + t[i];
        }
        s[k] = si - k;
    }

    for (const int qi : q) {
        cout << qi + x + s[(int)((qi + x) % 840LL)] + y << endl;
    }

    return 0;
}
