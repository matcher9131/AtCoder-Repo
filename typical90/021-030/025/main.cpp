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

vector<int> getMap(ll x) {
    vector<int> r(10);
    for (; x > 0; x /= 10) {
        ++r[x % 10];
    }
    return r;
}

int main() {
    ll n, b;
    cin >> n >> b;
    int d = to_string(n).size();

    ll ans = 0;
    function<void(string, int)> dfs = [&](string s, int from) {
        if ((int)s.size() > d) return;
        if (s.size()) {
            ll prod = accumulate(s.begin(), s.end(), 1LL, [](ll acc, char c) { return acc * (c - '0'); });
            ll m = prod + b;
            if (m <= n) {
                string ms = to_string(m);
                sort(ms.begin(), ms.end());
                if (s == ms) {
                    ++ans;
                }
            }
            
        }

        for (int i = from; i < 10; ++i) {
            dfs(s + (char)('0' + i), i);
        }
    };
    dfs("", 0);

    cout << ans << endl;
    return 0;
}