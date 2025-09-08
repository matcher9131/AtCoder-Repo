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
    int n, m;
    cin >> n >> m;
    vector<ll> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    vector<vector<int>> a(n);
    for (int j = 0; j < m; ++j) {
        int k;
        cin >> k;
        for (int ki = 0; ki < k; ++ki) {
            int i;
            cin >> i;
            --i;
            a[i].push_back(j);
        }
    }

    ll ans = 1e18;
    for (int pattern = 0; pattern < pow(3, n); ++pattern) {
        ll sum = 0;
        vector<int> animalCount(m);
        int p = pattern;
        for (int i = 0; i < n; ++i) {
            int count = p % 3;
            sum += count * c[i];
            for (const int animal : a[i]) {
                animalCount[animal] += count;
            }
            p /= 3;
        }
        if (all_of(animalCount.begin(), animalCount.end(), [](int x) { return x >= 2; })) {
            ans = min(ans, sum);
        }
    }

    cout << ans << endl;
    return 0;
}