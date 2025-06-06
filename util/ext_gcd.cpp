#include <utility>
using namespace std;
using ll = long long;

// 一次不定方程式ax + by = 1の特殊解(x, y)
// ※ max{|x|, |y|} <= max{|a|, |b|}
pair<ll, ll> ext_gcd(ll a, ll b) {
    if (b == 0) return { 1LL, 0 };
    auto [y, x] = ext_gcd(b, a % b);
    y -= a / b * x;
    return { x, y };
}
