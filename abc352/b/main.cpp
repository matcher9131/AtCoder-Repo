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
    string s, t;
    cin >> s >> t;

    vector<size_t> ans;
    size_t si = 0;
    for (size_t ti = 0; ti < t.size() && si < s.size(); ++ti) {
        if (t[ti] == s[si]) {
            ans.push_back(ti);
            ++si;
        }
    }

    for (int i = 0; i < (int)ans.size(); ++i) {
        cout << ans[i] + 1 << " \n"[i == (int)ans.size() - 1];
    }

    return 0;
}