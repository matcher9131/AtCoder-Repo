#include <vector>
using ll = long long;

extern int n;
extern int x;
extern std::vector<ll> a;

auto shakutori = [&]() {
    int right = 0;
    ll sum = 0;
    for (int left = 0; left < n; ++left) {
        while (right < n && sum + a[right] <= x) {
            sum += a[right];
            ++right;
        }

        /* some code here */

        if (right == left) {
            ++right;
        } else {
            sum -= a[left];
        }
    }
};

