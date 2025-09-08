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
    int n, m, k;
    cin >> n >> m >> k;
    vector<unsigned> success, fail;
    while (m--) {
        int c;
        cin >> c;
        unsigned pattern = 0;
        for (int i = 0; i < c; ++i) {
            int ai;
            cin >> ai;
            --ai;
            pattern |= 1u << ai;
        }
        string r;
        cin >> r;
        (r == "o" ? success : fail).push_back(pattern);
    }

    int ans = 0;
    for (unsigned bit = 0; bit < 1u << n; ++bit) {
        if (all_of(success.begin(), success.end(), [&](int pattern) { return popcount(pattern & bit) >= k; }) && all_of(fail.begin(), fail.end(), [&](int pattern) { return popcount(pattern & bit) < k; })) {
            ++ans;
        }
    }

    cout << ans << endl;
    return 0;
}