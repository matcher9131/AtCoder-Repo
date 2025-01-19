#include <cassert>
#include "../overflow.cpp"
using ll = long long;

int main() {
    auto [o1, v1] = multiply(3LL, 0LL, 2LL);
    assert(o1 == false);
    assert(v1 == 0LL);

    auto [o2, v2] = multiply(1LL, 4LL, 8LL);
    assert(o2 == false);
    assert(v2 == 32LL);

    auto [o3, v3] = multiply((ll)3e9, (ll)3e9);
    assert(o3 == false);
    assert(v3 == (ll)9e18);

    auto [o4, v4] = multiply((ll)3.1e9, (ll)3.1e9);
    assert(o4 == true);
    assert(v4 == 0LL);

    auto [o5, v5] = multiply((ll)3.1e9, (ll)3.1e9, 0LL);
    assert(o5 == false);
    assert(v5 == 0LL);

    return 0;
}