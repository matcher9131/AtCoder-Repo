#include <utility>
#include <climits>
using namespace std;
using ll = long long;

template<typename... Args>
pair<bool, ll> multiply(Args... args) {
    ll x = 1LL;
    bool overflows = false;
    for (const ll y : initializer_list<ll>{ args... }) {
        if (y == 0) return make_pair(false, 0);
        if (x > LLONG_MAX / y) {
            overflows = true;
        } else {
            x *= y;
        }
    }
    return overflows ? make_pair(true, 0LL) : make_pair(false, x);
}
