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
    // ci, ai, i
    vector<tuple<int, int, int>> card(n);
    for (int i = 0; i < n; ++i) {
        int ai, ci;
        cin >> ai >> ci;
        card[i] = { ci, ai, i };
    }
    sort(card.begin(), card.end());

    set<int> a;
    vector<int> ans;
    for (const auto& [cost, power, index] : card) {
        if (a.upper_bound(power) == a.end()) {
            ans.push_back(index);
            a.insert(power);
        }
    }
    sort(ans.begin(), ans.end());

    cout << ans.size() << endl;
    for (int i = 0; i < (int)ans.size(); ++i) {
        cout << ans[i] + 1 << " \n"[i == (int)ans.size() - 1];
    }

    return 0;
}