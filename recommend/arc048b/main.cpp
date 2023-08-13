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
using namespace std;
using ll = long long;


int main() {
    int n;
    cin >> n;
    // Rate, Hand, Index
    vector<tuple<int, int, int>> r(n);
    unordered_map<int, vector<int>> h;
    vector<int> win(n), lose(n), draw(n);
    for (int i = 0; i < n; ++i) {
        int ri, hi;
        cin >> ri >> hi;
        --hi;
        r[i] = make_tuple(ri, hi, i);
        if (h.find(ri) == h.end()) {
            h.emplace(ri, vector<int>(3));
        }
        ++h[ri][hi];
    }
    sort(r.begin(), r.end());

    auto comparer = [](const tuple<int, int, int> &x, const tuple<int, int, int> &y) {
        return get<0>(x) < get<0>(y);
    };
    for (int i = 0; i < n; ++i) {
        auto [rate, hand, index] = r[i];
        auto lower = lower_bound(r.begin(), r.end(), make_tuple(rate, -1, -1), comparer);
        auto upper = upper_bound(r.begin(), r.end(), make_tuple(rate, -1, -1), comparer);
        win[index] = lower - r.begin() + h[rate][(hand + 1) % 3];
        lose[index] = n - (upper - r.begin()) + h[rate][(hand + 2) % 3];
        draw[index] = n - 1 - win[index] - lose[index];
        // assert(draw[index] == h[rate][hand] - 1);
    }

    for (int i = 0; i < n; ++i) {
        cout << win[i] << " " << lose[i] << " " << draw[i] << endl;
    }

    return 0;
}