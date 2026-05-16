#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

struct Vector2D {
    ll x;
    ll y;

    strong_ordering operator<=>(const Vector2D& other) const {
        return x * other.y - y * other.x <=> 0;
    }

    bool operator==(const Vector2D& other) const {
        return x * other.y == y * other.x;
    }
};

bool isUpper(Vector2D &p) {
    return p.y > 0 || (p.y == 0 && p.x > 0);
}

int main() {
    ll n, nq;
    cin >> n >> nq;
    vector<Vector2D> p(n);
    
    vector<Vector2D> upper; // 0 <= arg < pi
    vector<Vector2D> lower; // pi <= arg < 2pi
    for (ll i = 0; i < n; ++i) {
        cin >> p[i].x >> p[i].y;
        (isUpper(p[i]) ? upper : lower).emplace_back(p[i]); 
    }

    sort(upper.begin(), upper.end());
    sort(lower.begin(), lower.end());

    while (nq--) {
        ll i, j;
        cin >> i >> j;
        --i;
        --j;

        bool isUpper1 = isUpper(p[i]);
        bool isUpper2 = isUpper(p[j]);
        if (isUpper1) {
            if (isUpper2) {
                if (p[i] <= p[j]) {
                    cout << upper_bound(upper.begin(), upper.end(), p[j]) - lower_bound(upper.begin(), upper.end(), p[i]) << endl;
                } else {
                    ll ans = (upper.end() - lower_bound(upper.begin(), upper.end(), p[i]))
                        + (ll)lower.size()
                        + (upper_bound(upper.begin(), upper.end(), p[j]) - upper.begin());
                    cout << ans << endl;
                }
            } else {
                ll ans = (upper.end() - lower_bound(upper.begin(), upper.end(), p[i]))
                    + (upper_bound(lower.begin(), lower.end(), p[j]) - lower.begin());
                cout << ans << endl;
            }
        } else {
            if (isUpper2) {
                ll ans = (lower.end() - lower_bound(lower.begin(), lower.end(), p[i]))
                    + (upper_bound(upper.begin(), upper.end(), p[j]) - upper.begin());
                cout << ans << endl;
            } else {
                if (p[i] <= p[j]) {
                    cout << upper_bound(lower.begin(), lower.end(), p[j]) - lower_bound(lower.begin(), lower.end(), p[i]) << endl;
                } else {
                    ll ans = (lower.end() - lower_bound(lower.begin(), lower.end(), p[i]))
                        + (ll)upper.size()
                        + (upper_bound(lower.begin(), lower.end(), p[j]) - lower.begin());
                    cout << ans << endl;
                }
            }
        }
    }


    return 0;
}