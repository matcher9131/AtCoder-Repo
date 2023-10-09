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

    auto mod = [&](int i) {
        return (i % n + n) % n;
    };

    int t, x, y;
    int shift = 0;
    for (int j = 0; j < q; ++j) {
        cin >> t >> x >> y;
        --x;
        --y;
        if (t == 1) {
            x = mod(x - shift);
            y = mod(y - shift);
            swap(a[x], a[y]);
        } else if (t == 2) {
            ++shift;
        } else if (t == 3) {
            cout << a[mod(x - shift)] << endl;
        }
    }

    return 0;
}