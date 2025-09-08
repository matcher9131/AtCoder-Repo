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
    int n, k;
    cin >> n >> k;
    // value, index
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; ++i) {
        int pi;
        cin >> pi;
        p[i] = { pi, i };
    }
    sort(p.begin(), p.end());

    set<int> s;
    int ans = 1e8;
    for (int i = 0; i < n; ++i) {
        if ((int)s.size() < k) {
            s.insert(p[i].second);
        } else {
            ans = min(ans, *s.rbegin() - *s.begin());
            s.insert(p[i].second);
            s.erase(p[i-k].second);
        }
    }
    ans = min(ans, *s.rbegin() - *s.begin());

    cout << ans << endl;
    return 0;
}