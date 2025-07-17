#include <algorithm>
#include <functional>
using namespace std;
using ll = long long;

extern ll INITIAL_NG;
extern ll INITIAL_OK;
extern bool isOK(ll);


function<ll()> binary_search = [&]() {
    ll ng = INITIAL_NG;
    ll ok = INITIAL_OK;

    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if (isOK(mid)) ok = mid;
        else ng = mid;
    }
    return ok;
};