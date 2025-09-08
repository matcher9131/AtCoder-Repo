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
    string s;
    cin >> n >> s;
    vector<ll> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    vector<char> m{'0', '1'};
    vector<ll> l0(n), l1(n), r0(n), r1(n);
    l0[0] = s[0] == '0' ? 0 : c[0];
    l1[0] = s[0] == '0' ? c[0] : 0;
    for (int i = 1; i < n; ++i) {
        if (s[i] == m[i%2]) {
            l0[i] = l0[i-1];
            l1[i] = l1[i-1] + c[i];
        } else {
            l0[i] = l0[i-1] + c[i];
            l1[i] = l1[i-1];
        }
    }
    r0[0] = s[n-1] == '0' ? 0 : c[n-1];
    r1[0] = s[n-1] == '0' ? c[n-1] : 0;
    for (int j = 1; j < n; ++j) {
        int i = n-1-j;
        if (s[i] == m[j%2]) {
            r0[j] = r0[j-1];
            r1[j] = r1[j-1] + c[i];
        } else {
            r0[j] = r0[j-1] + c[i];
            r1[j] = r1[j-1];
        }
    }

    ll ans = 1e18;
    if (n % 2) {
        for (int i = 0; i < n-1; ++i) {
            ans = min(ans, l0[i] + r1[n-2-i]);
            ans = min(ans, l1[i] + r0[n-2-i]);
        }
    } else {
        for (int i = 0; i < n-1; ++i) {
            ans = min(ans, l0[i] + r0[n-2-i]);
            ans = min(ans, l1[i] + r1[n-2-i]);
        }
    }

    cout << ans << endl;
    return 0;
}