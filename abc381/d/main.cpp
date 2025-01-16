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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<vector<int>> sucs;
    for (int i = 0; i < n; i += 2) {
        vector<int> suc;
        for (; i + 1 < n; i += 2) {
            if (a[i] != a[i+1]) break;
            suc.push_back(a[i]);
        }
        if (!suc.empty()) {
            sucs.emplace_back(suc);
        }
    }
    for (int i = 1; i < n; i += 2) {
        vector<int> suc;
        for (; i + 1 < n; i += 2) {
            if (a[i] != a[i+1]) break;
            suc.push_back(a[i]);
        }
        if (!suc.empty()) {
            sucs.emplace_back(suc);
        }
    }


    int ans = 0;
    for (const auto& suc : sucs) {
        int right = 0;
        unordered_set<int> s;
        for (int left = 0; left < suc.size(); ++left) {
            while (right < suc.size() && !s.contains(suc[right])) {
                s.insert(suc[right]);
                ++right;
            }

            ans = max(ans, (int)s.size() * 2);

            if (right == left) {
                ++right;
            } else {
                s.erase(suc[left]);
            }
        }
    }

    cout << ans << endl;

    return 0;
}