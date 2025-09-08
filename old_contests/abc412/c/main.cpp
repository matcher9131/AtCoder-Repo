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

void solve() {
    int n;
    cin >> n;
    vector<int> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    sort(s.begin() + 1, s.end() - 1);

    int i = 0;
    int ans = 1;
    while (true) {
        if (s[i] * 2 >= s[n-1]) {
            cout << ans+1 << endl;
            return;
        }
        int j = upper_bound(s.begin() + 1, s.end() - 1, s[i] * 2) - s.begin() - 1;
        if (j <= i) {
            cout << -1 << endl;
            return;
        }
        ++ans;
        i = j;
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}