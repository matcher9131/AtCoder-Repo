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
    unordered_map<ll, pair<int, int>> mp;

    for (int i = 0; i < n; ++i) {
        int mi;
        cin >> mi;
        while (mi--) {
            ll p;
            int e;
            cin >> p >> e;
            if (mp[p].first < e) {
                mp[p] = { e, i };
            } else if (mp[p].first == e) {
                mp[p].second = -1;
            }
        }
    }

    unordered_set<int> s;
    for (const auto& [k, v] : mp) {
        if (v.second != -1) {
            s.insert(v.second);
        }
    }

    cout << (int)s.size() + ((int)s.size() < n ? 1 : 0) << endl;
    return 0;
}