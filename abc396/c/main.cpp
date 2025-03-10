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
    cin >> n >> m;
    vector<ll> b(n), w(m);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> w[i];
    }
    sort(b.begin(), b.end(), greater<ll>());
    sort(w.begin(), w.end(), greater<ll>());

    vector<ll> sb(n + 1);
    for (int i = 0; i < n; ++i) {
        sb[i+1] = sb[i] + b[i];
    }
    vector<ll> swMax(m + 1);
    ll sw = 0;
    for (int i = 0; i < m; ++i) {
        sw += w[i];
        swMax[i+1] = sw > swMax[i] ? sw : swMax[i];
    }
    

    ll ans = 0;
    for (int i = 0; i <= n; ++i) {
        ll s = sb[i] + swMax[min(i, m)];
        ans = max(ans, s);
    }

    cout << ans << endl;

    return 0;
}