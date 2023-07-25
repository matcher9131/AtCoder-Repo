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
using namespace std;
using ll = long long;

class mint {
    static constexpr ll MOD = 998244353ULL;
private:
    ll _v;
public :
    mint(int val) {
        _v = (ll)val % MOD;
    }
    mint(): _v(0) {}

    int value() {
        return (int)_v;
    }

    mint& operator +=(const mint& rhs) {
        _v += rhs._v;
        if (_v >= MOD) _v -= MOD;
        return *this;
    }
    
    mint& operator -=(const mint& rhs) {
        _v += MOD - rhs._v;
        if (_v >= MOD) _v -= MOD;
        return *this;
    }

    mint& operator *=(const mint& rhs) {
        ll t = _v * rhs._v % MOD;
        if (t < 0) t += MOD;
        _v = t;
        return *this;
    }

    mint power(int n) const {
        assert(n >= 0);
        mint x = *this, result = mint(1);
        while (n) {
            if (n & 1) result *= x;
            x *= x;
            n >>= 1;
        }
        return result;
    }

    mint inv() const {
        return power((int)MOD - 2);
    }

    mint& operator /=(const mint& rhs) {
        return *this = *this * rhs.inv();
    }

    friend mint operator +(const mint& lhs, const mint& rhs) {
        return mint(lhs) += rhs;
    }

    friend mint operator -(const mint& lhs, const mint& rhs) {
        return mint(lhs) -= rhs;
    }

    friend mint operator *(const mint& lhs, const mint& rhs) {
        return mint(lhs) *= rhs;
    }

    friend mint operator /(const mint& lhs, const mint& rhs) {
        return mint(lhs) /= rhs;
    }

    friend bool operator ==(const mint& lhs, const mint& rhs) {
        return lhs._v == rhs._v;
    }

    friend bool operator !=(const mint& lhs, const mint& rhs) {
        return lhs._v != rhs._v;
    }
};

int main() {
    ll n;
    cin >> n;

    int a1 = 0, a2 = 0, a3 = 0;
    while (n % 2 == 0) {
        n /= 2;
        ++a1;
    }
    while (n % 3 == 0) {
        n /= 3;
        ++a2;
    }
    while (n % 5 == 0) {
        n /= 5;
        ++a3;
    }
    if (n > 1) {
        cout << 0 << endl;
        return 0;
    }
    
    //
    //cout << "a1 = " << a1 << ", a2 = " << a2 << ", a3 = " << a3 << endl;
    //

    vector<vector<vector<mint>>> dp(a1 + 1, vector<vector<mint>>(a2 + 1, vector<mint>(a3 + 1)));
    dp[0][0][0] = mint(1);

    for (int i = 0; i <= a1; ++i) {
        for (int j = 0; j <= a2; ++j) {
            for (int k = 0; k <= a3; ++k) {
                if (i == 0 && j == 0 && k == 0) continue;
                mint r = mint(0);
                if (i > 0) r += dp[i - 1][j][k] / mint(5);
                if (j > 0) r += dp[i][j - 1][k] / mint(5);
                if (i > 1) r += dp[i - 2][j][k] / mint(5);
                if (k > 0) r += dp[i][j][k - 1] / mint(5);
                if (i > 0 && j > 0) r += dp[i - 1][j - 1][k] / mint(5);
                dp[i][j][k] = r;
            }
        }
    }

    cout << dp[a1][a2][a3].value() << endl;

    //
    //cout << "dp[0][0][0] = " << dp[0][0][0].value() << endl;
    //cout << "dp[1][0][0] = " << dp[1][0][0].value() << endl;
    //cout << "dp[0][1][0] = " << dp[0][1][0].value() << endl;
    //cout << "dp[1][1][0] = " << dp[1][1][0].value() << endl;
    //

    return 0;
}