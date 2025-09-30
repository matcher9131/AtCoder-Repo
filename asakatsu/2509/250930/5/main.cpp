#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

class LargeSmallSet {
private:
    ll _lowerSum = 0;
    ll _upperSum = 0;
    multiset<ll, greater<>> _lower;
    multiset<ll> _upper;
    void _flatten() {
        while ((ll)_upper.size() - (ll)_lower.size() > 1) {
            auto it = _upper.begin();
            _lower.insert(*it);
            _lowerSum += *it;
            _upperSum -= *it;
            _upper.erase(it);
        }
        while ((ll)_lower.size() - (ll)_upper.size() > 1) {
            auto it = _lower.begin();
            _upper.insert(*it);
            _upperSum += *it;
            _lowerSum -= *it;
            _lower.erase(it);
        }
    }
public:
    void insert(ll x) {
        ll med = _lower.empty() ? -INF : *_lower.begin();
        if (x > med) {
            _upper.insert(x);
            _upperSum += x;
        } else {
            _lower.insert(x);
            _lowerSum += x;
        }
        this->_flatten();
    }

    void erase(ll x) {
        ll med = _lower.empty() ? -INF : *_lower.begin();
        if (x > med) {
            auto it = _upper.find(x);
            if (it != _upper.end()) {
                _upper.erase(it);
                _upperSum -= x;
            }
        } else {
            auto it = _lower.find(x);
            if (it != _lower.end()) {
                _lower.erase(it);
                _lowerSum -= x;
            }
        }
        this->_flatten();
    }

    ll getUpperSum() { return this->_upperSum; }
    ll getLowerSum() { return this->_lowerSum; }
};

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if (n%2) {
        LargeSmallSet left, right;
        for (ll i = 1; i < n; ++i) {
            right.insert(a[i]);
        }
        ll ans = right.getUpperSum() - right.getLowerSum();
        for (ll i = 2; i < n; i += 2) {
            right.erase(a[i-1]);
            right.erase(a[i]);
            left.insert(a[i-2]);
            left.insert(a[i-1]);
            chmax(ans, right.getUpperSum() - right.getLowerSum() + left.getUpperSum() - left.getLowerSum());
        }
        cout << ans << endl;
    } else {
        sort(a.begin(), a.end());
        cout << accumulate(a.begin() + n/2, a.end(), 0LL) - accumulate(a.begin(), a.begin() + n/2, 0LL) << endl;
    }

    return 0;
}