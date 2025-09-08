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
    int nq;
    cin >> nq;
    vector<pair<int, ll>> q;
    for (int i = 0; i < nq; ++i) {
        int k;
        cin >> k;
        if (k == 1) {
            ll l;
            cin >> l;
            q.emplace_back(1, l);
        } else if (k == 2) {
            q.emplace_back(2, 0);
        } else if (k == 3) {
            ll i;
            cin >> i;
            --i;
            q.emplace_back(3, i);
        }
    }

    // left, length
    vector<pair<ll, ll>> snakes;
    ll right = 0;
    ll left = 0;
    int removed = 0;
    for (const auto& [k, x] : q) {
        if (k == 1) {
            snakes.emplace_back(right, x);
            right += x;
        } else if (k == 2) {
            left += snakes[removed].second;
            ++removed;
        } else if (k == 3) {
            cout << snakes[removed + x].first - left << endl;
        }
    }

    return 0;
}