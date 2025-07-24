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
    ll n;
    string r, c;
    cin >> n >> r >> c;

    vector<string> g;
    auto gridIsOK = [&]() -> bool {
        for (ll j = 0; j < n; ++j) {
            vector<int> nch(3);
            bool isFirst = true;
            for (ll i = 0; i < n; ++i) {
                if (g[i][j] != '.') {
                    if (isFirst && g[i][j] != c[j]) return false;
                    isFirst = false;
                    ++nch[g[i][j] - 'A'];
                }
            }
            if (nch[0] != 1 || nch[1] != 1 || nch[2] != 1) return false;
        }
        return true;
    };
    auto rowIsOK = [&](int i, string &s) -> bool {
        for (ll j = 0; j < n; ++j) {
            if (s[j] == r[i]) return true;
            else if (s[j] != '.') return false;
        }
        return false;
    };

    vector<string> sample(n, string(n-3, '.'));
    for (ll i = 0; i < n; ++i) {
        sample[i] += "ABC";
    }
    function<void(int)> dfs = [&](int i) {
        if (i == n) {
            if (gridIsOK()) {
                cout << "Yes" << endl;
                for (ll ri = 0; ri < n; ++ri) {
                    cout << g[ri] << endl;
                }
                exit(0);
            }
        } else {
            do {
                if (!rowIsOK(i, sample[i])) continue;
                g.push_back(sample[i]);
                dfs(i+1);
                g.pop_back();
            } while (next_permutation(sample[i].begin(), sample[i].end()));
        }
    };
    dfs(0);

    cout << "No" << endl;
    return 0;
}