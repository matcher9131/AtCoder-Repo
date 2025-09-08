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
    string s;
    cin >> n >> s;
    s += '_';

    vector<ll> count(26);
    char current = s[0];
    ll left = 0;
    for (ll i = 0; i <= n; ++i) {
        if (s[i] != current) {
            count[current - 'a'] = max(count[current - 'a'], i - left);
            current = s[i];
            left = i;
        }
    }

    cout << accumulate(count.begin(), count.end(), 0LL) << endl;
    return 0;
}