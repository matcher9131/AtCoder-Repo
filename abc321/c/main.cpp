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

int count_bit(int i) {
    int c = 0;
    for (int j = 0; j < 10; ++j) {
        if (i & (1 << j)) ++c;
    }
    return c;
}

int main() {
    ll k;
    cin >> k;

    ll i = 0;
    for (int digits = 1; digits <= 10; ++digits) {
        for (int bit = 2; bit < 1024; ++bit) {
            if (count_bit(bit) == digits) ++i;
            if (i == k) {
                ll ans = 0;
                for (int j = 9; j >= 0; --j) {
                    if (bit & (1 << j)) {
                        ans *= 10;
                        ans += j;
                    }
                }
                cout << ans << endl;
                return 0;
            }
        }
    }

    return 0;
}
