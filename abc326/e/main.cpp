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
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<mint> sp(n + 1);
    sp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        sp[i] = sp[i - 1] / n + sp[i - 1];
    }

    mint ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += a[i - 1] * (sp[i] - sp[i - 1]);
    }

    cout << ans.val() << endl;

    return 0;
}