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
    ll n, l, r;
    cin >> n >> l >> r;
    vector<ll> ans(n);
    for (ll i = 0; i < n; ++i) {
        ll ai;
        cin >> ai;
        if (ai <= l) ans[i] = l;
        else if (ai >= r) ans[i] = r;
        else ans[i] = ai;
    }

    for (ll i = 0; i < (ll)ans.size(); ++i) {
        cout << ans[i] << " \n"[i == (ll)ans.size() - 1];
    }
    
    return 0;
}