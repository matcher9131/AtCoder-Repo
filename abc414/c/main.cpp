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
    int a;
    ll n;
    cin >> a >> n;

    // 2m-1桁の回文
    auto palin1 = [](ll i) -> ll {
        ll j = i;
        ll lower = 0;
        ll shift = 1;
        while (j > 0) {
            lower *= 10;
            lower += j % 10;
            j /= 10;
            shift *= 10;
        }
        return i / 10 * shift + lower;
    };
    // 2m桁の回文
    auto palin2 = [](ll i) -> ll {
        ll j = i;
        ll lower = 0;
        while (j > 0) {
            lower *= 10;
            lower += j % 10;
            j /= 10;
            i *= 10;
        }
        return i + lower;
    };
    auto is_a_palin = [&](ll i) -> bool {
        vector<int> result;
        while (i > 0) {
            result.push_back(i % a);
            i /= a;
        }
        int m = result.size();
        for (int j = 0; j < m / 2; ++j) {
            if (result[j] != result[m-1-j]) return false;
        }
        return true;
    };

    ll ans = 0;
    for (ll i = 1; i <= 999999LL; ++i) {
        ll p1 = palin1(i);
        if (p1 > n) break;
        if (is_a_palin(p1)) ans += p1;
        ll p2 = palin2(i);
        if (p2 <= n && is_a_palin(p2)) ans += p2;
    }

    cout << ans << endl;
    return 0;
}