#include <cassert>
using ll = unsigned long long;

class mint {
    static constexpr ll MOD = 998244353ULL;
private:
    ll _v;
public :
    mint(int val) {
        _v = (ll)val % MOD;
    }

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