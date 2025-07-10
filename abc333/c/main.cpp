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
    int n;
    cin >> n;

    vector<ll> rep(13);
    rep[0] = 1;
    for (int i = 1; i < 13; ++i) {
        rep[i] = 10 * rep[i-1] + 1;
    }

    int i = 0, j = 0, k = 0;
    ll ans = 0;
    for (int ni = 0; ni < n; ++ni) {
        ans = rep[i] + rep[j] + rep[k];
        if (i < j) {
            ++i;
        } else if (j < k) {
            i = 0;
            ++j;
        } else {
            i = 0;
            j = 0;
            ++k;
        }
    }

    cout << ans << endl;
    return 0;
}