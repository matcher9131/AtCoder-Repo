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
    int h, w;
    cin >> h >> w;
    vector<vector<ll>> a(h, vector<ll>(w));
    ll ans = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> a[i][j];
            ans ^= a[i][j];
        }
    }

    map<ll, ll> visited;
    function<void(ll, ll)> dfs = [&](ll bit, ll value) -> void {
        visited[bit] = value;
        ans = max(ans, value);
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                ll mask = 1 << (i * w + j);
                if (bit & mask) continue;
                if (i < h-1) {
                    ll dMask = 1 << ((i+1) * w + j);
                    if ((bit & dMask) == 0) {
                        ll newBit = bit | mask | dMask;
                        if (!visited.contains(newBit)) {
                            dfs(newBit, value ^ a[i][j] ^ a[i+1][j]);
                        }
                    }
                }
                if (j < w-1) {
                    ll rMask = 1 << (i * w + j + 1);
                    if ((bit & rMask) == 0) {
                        ll newBit = bit | mask | rMask;
                        if (!visited.contains(newBit)) {
                            dfs(newBit, value ^ a[i][j] ^ a[i][j+1]);
                        }
                    }
                }
            }
        }
    };
    dfs(0, ans);

    cout << ans << endl;
    return 0;
}