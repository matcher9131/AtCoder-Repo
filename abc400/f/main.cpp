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
#include <atcoder/fenwicktree>
using namespace std;
using ll = long long;

int inline pmod(int x, int y) {
    int r = x % y;
    return r >= 0 ? r : r + y;
}

int main() {
    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        --c[i];
    }
    vector<ll> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    vector<vector<int>> revC(n);
    for (int i = 0; i < n; ++i) {
        revC[c[i]].push_back(i);
    }
    for (int ci = 0; ci < n; ++ci) {
        int size = (int)revC[ci].size();
        if (size <= 1) continue;
        vector<int> d(size);
        for (int i = 0; i < size; ++i) {
            d[i] = pmod(revC[ci][(i+1) % size] - revC[ci][i], n);
        }
        int maxIndex = max_element(d.begin(), d.end()) - d.begin();
        for (int i = 0; i <= maxIndex; ++i) {
            revC[ci][i] += n;
        }
        sort(revC[ci].begin(), revC[ci].end());
    }

    ll ans = 0;
    atcoder::fenwick_tree<int> fw(2 * n);
    vector<pair<ll, int>> cost(n);
    for (int i = 0; i < n; ++i) {
        cost[i].second = i;
    }

    while (!cost.empty()) {
        for (int ci = 0; ci < n; ++ci) {
            int size = revC[ci].size();
            for (int i = 0; i < size; ++i) {
                int l = revC[ci][i];
                for (int j = i + 1; j < size; ++j) {
                    int r = revC[ci][j];
                    ll sep = (j - i + 1) * (1 + x[ci]);
                    if (fw.sum(l, r + 1) > 0) {
                        ll cont = r - l + 1 + x[ci];
                        if (sep <= cont) {
                            ans += sep;
                            i = j;
                            break;
                        }
                    }
                    
                }
            }
        }
    }
    

    return 0;
}