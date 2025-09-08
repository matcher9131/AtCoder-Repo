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
    ll n;
    cin >> n;
    vector<string> s(n);
    for (ll i = 0; i < n; ++i) {
        cin >> s[i];
    }

    vector<int> numRowCircle(n);
    vector<int> numColCircle(n);
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            if (s[i][j] == 'o') {
                ++numRowCircle[i];
                ++numColCircle[j];
            }
        }
    }

    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            if (s[i][j] == 'o') {
                ans += (numRowCircle[i] - 1) * (numColCircle[j] - 1);
            }
        }
    }

    cout << ans << endl;
    return 0;
}