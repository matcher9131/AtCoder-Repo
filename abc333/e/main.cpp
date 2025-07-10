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
    vector<pair<int, int>> event(n);
    for (int i = 0; i < n; ++i) {
        int ti, xi;
        cin >> ti >> xi;
        --xi;
        event[i] = { ti, xi };
    }

    vector<int> mobs(n);
    vector<int> ans;
    int kMin = 0;
    int k = 0;
    for (int i = n - 1; i >= 0; --i) {
        auto [ti, xi] = event[i];
        if (ti == 1) {
            if (mobs[xi] > 0) {
                ans.push_back(1);
                --mobs[xi];
                --k;
            } else {
                ans.push_back(0);
            }
        } else {
            ++mobs[xi];
            ++k;
            kMin = max(kMin, k);
        }
    }
    reverse(ans.begin(), ans.end());

    if (any_of(mobs.begin(), mobs.end(), [](int val) { return val > 0; })) {
        cout << -1 << endl;
    } else {
        cout << kMin << endl;
        for (int i = 0; i < (int)ans.size(); ++i) {
            cout << ans[i] << " \n"[i == (int)ans.size() - 1];
        }
    }

    return 0;
}