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

constexpr int INF = 1e9 + 1;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int q;
    cin >> q;
    vector<int> b(q);
    for (int j = 0; j < q; ++j) {
        cin >> b[j];
    }

    for (int j = 0; j < q; ++j) {
        int dif = INF;
        auto it = lower_bound(a.begin(), a.end(), b[j]);
        if (it != a.end()) {
            dif = *it - b[j];
        }
        if (it != a.begin()) {
            --it;
            dif = min(dif, b[j] - *it);
        }
        cout << dif << endl;
    }

    return 0;
}