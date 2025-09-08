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
using namespace std;
using ll = long long;


int main() {
    ll n;
    cin >> n;

    ll ans = (ll)sqrtl(n);

    auto count = [&](int exp) -> ll {
        for (ll i = 2; ; ++i) {
            if (powl(i, exp) > n) return i - 2;
        }
    };

    ans += count(3);
    ans += count(5);
    ans -= count(6);
    ans += count(7);
    ans -= count(10);
    ans += count(11);
    ans += count(13);
    ans -= count(14);
    ans -= count(15);
    ans += count(17);
    ans += count(19);
    ans -= count(21);
    ans -= count(22);
    ans += count(23);
    ans -= count(26);
    ans += count(29);
    ans += count(30);
    ans += count(31);
    ans -= count(33);
    ans -= count(34);
    ans -= count(35);
    ans += count(37);
    ans -= count(38);
    ans -= count(39);
    ans += count(41);
    ans += count(42);
    ans += count(43);
    ans -= count(46);
    ans += count(47);
    ans -= count(51);
    ans += count(53);
    ans -= count(55);
    ans -= count(57);
    ans -= count(58);
    ans += count(59);

    cout << ans << endl;

    return 0;
}