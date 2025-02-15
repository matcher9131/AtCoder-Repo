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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<int> b(q), k(q);
    for (int i = 0; i < q; ++i) {
        cin >> b[i] >> k[i];
    }

    // [l, r]にあるa_iの個数がcount以上かどうか
    auto isOK = [&](int l, int r, int count) -> bool {
        return lower_bound(a.begin(), a.end(), r + 1) - lower_bound(a.begin(), a.end(), l) >= count;
    };

    for (int i = 0; i < q; ++i) {
        int ok = 1e9;
        int ng = -1;
        while (ok - ng > 1) {
            int mid = (ok + ng) / 2;
            if (isOK(b[i] - mid, b[i] + mid, k[i])) ok = mid;
            else ng = mid;
        }
        cout << ok << endl;
    }

    return 0;
}