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

int numDigits(int x) {
    int r = 0;
    while (x > 0) {
        x /= 10;
        ++r;
    }
    return r;
}

mint inline getMul(int x) {
    return ((mint)10).pow(numDigits(x));
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<mint> mul(n);
    mul[0] = getMul(a[0]);
    for (int i = 1; i < n; ++i) {
        mul[i] = mul[i-1] + getMul(a[i]);
    }

    mint ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        ans += (mint)a[i] * (mul[n-1] - mul[i]);
    }
    for (int i = 1; i < n; ++i) {
        ans += (mint)a[i] * i;
    }

    cout << ans.val() << endl;
    return 0;
}