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
#include <atcoder/modint>
#include <atcoder/fenwicktree>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        int ai;
        cin >> ai;
        a[i] = { ai, i };
    }
    sort(a.begin(), a.end(), greater<>());

    mint base2 = 2;
    mint ans = 0;
    atcoder::fenwick_tree<mint> fw(n);
    for (const auto &[ai, i] : a) {
        if (i > 0) {
            mint ng = fw.sum(0, i) / base2.pow(n - i);
            ans += base2.pow(i) - 1 - ng;
        }
        fw.add(i, base2.pow(n-1-i));
    }

    cout << ans.val() << endl;
    return 0;
}