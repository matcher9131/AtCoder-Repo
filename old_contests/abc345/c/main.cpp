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
    string s;
    cin >> s;
    ll n = s.size();

    vector<ll> numCh(26);
    for (int i = 0; i < n; ++i) {
        ++numCh[s[i] - 'a'];
    }

    ll ans = n * (n - 1) / 2;
    bool dup = false;
    for (const ll nc : numCh) {
        if (nc > 1) {
            ans -= nc * (nc - 1) / 2;
            dup = true;
        }
    }
    if (dup) {
        ++ans;
    }

    cout << ans << endl;
    return 0;
}