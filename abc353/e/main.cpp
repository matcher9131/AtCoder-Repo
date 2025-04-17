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
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    sort(s.begin(), s.end());

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        string t = "";
        for (int j = 0; j < (int)s[i].size(); ++j) {
            t += s[i][j];
            ll val = lower_bound(s.begin(), s.end(), t + '~') - lower_bound(s.begin(), s.end(), t);
            ans += val;
        }
        ans -= (ll)s[i].size();
    }
    ans /= 2;

    cout << ans << endl;
    return 0;
}