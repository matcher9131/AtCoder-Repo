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
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> chIndexes(26, vector<int>());
    for (int i = 0; i < n; ++i) {
        chIndexes[s[i] - 'A'].push_back(i);
    }

    ll ans = 0;
    for (int j = 1; j < n - 1; ++j) {
        for (const auto& ch : chIndexes) {
            ll l = lower_bound(ch.begin(), ch.end(), j) - ch.begin();
            ll r = (l < ch.size() && ch[l] == j) ? ch.size() - l - 1 : ch.size() - l;
            ans += l * r;
        }
    }

    cout << ans << endl;

    return 0;
}