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
    string t;
    cin >> n >> t;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    vector<int> l(n), r(n);
    for (int i = 0; i < n; ++i) {
        int li = 0;
        int j = 0;
        for (; j < t.size(); ++j) {
            li = s[i].find(t[j], li);
            if (li == string::npos) break;
        }
        l[i] = j;
    }
    for (int i = 0; i < n; ++i) {
        int ri = s[i].size() - 1;
        int j = 0;
        for (; j < t.size(); ++j) {
            ri = s[i].find_last_of(t[t.size() - 1 - j], ri);
            if (ri == string::npos) break;
        }
        r[i] = j;
    }

    vector<int> c(t.size() + 1);
    for (const int ri : r) {
        ++c[ri];
    }

    ll ans = 0;
    for (const int li : l) {
        for (int i = max(0, (int)t.size() - li); i <= t.size(); ++i) {
            ans += c[i];
        }
    }

    cout << ans << endl;

    return 0;
}