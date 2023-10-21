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
    vector<pair<ll, ll>> t(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i].first >> t[i].second;
        t[i].second += t[i].first;
    }
    sort(t.begin(), t.end());

    int ans = 0;
    priority_queue<ll, vector<ll>, greater<ll>> que;
    auto it = t.begin();
    for (ll current = 0; ; ++current) {
        if (que.empty()) {
            if (it == t.end()) break;
            current = it->first;
        }
        for (; it != t.end() && it->first == current; ++it) que.push(it->second);
        while (!que.empty() && que.top() < current) que.pop();
        if (!que.empty()) {
            ++ans;
            que.pop();
        }
    }

    cout << ans << endl;

    return 0;
}