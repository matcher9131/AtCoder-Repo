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
using ull = unsigned long long;
using mint = atcoder::modint998244353;

mint base2 = 2;
vector<mint> fact(61);
void pre() {
    fact[0] = 1;
    for (int i = 1; i <= 60; ++i) {
        fact[i] = fact[i-1] * i;
    }
}

mint comb(int n, int k) {
    return fact[n] / (fact[k] * fact[n-k]);
} 

void solve() {
    ull n;
    int k;
    cin >> n >> k;

    mint ans = 0;
    int d = bit_width(n);

    auto sumdk = [&](int d, int k, mint upper) {
        if (d < k) return (mint)0;
        return comb(d-1, k-1) * (base2.pow(d) - 1) + comb(d, k) * upper;
    };
    
    int one = 0;
    mint upper = 0;
    for (int i = d - 1; i >= 0; --i) {
        
        if (n & (1ULL << i)) {
            if (k > one) {
                ans += sumdk(i, k-one, upper);
            } else if (k == one) {
                ans += upper;
            }
            ++one;
            upper += base2.pow(i);
        }
    }
    if (popcount(n) == k) ans += n;

    cout << ans.val() << endl;
}


int main() {
    pre();
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}