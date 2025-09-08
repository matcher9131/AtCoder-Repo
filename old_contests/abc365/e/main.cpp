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
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<ll> s(n+1);
    for (int i = 0; i < n; ++i) {
        s[i+1] = s[i] ^ a[i];
    }

    // sb[i][j] = s_0, s_1, ... s_iの中でjビット目が1であるものの個数 
    vector<vector<int>> sb(n + 1, vector<int>(31));
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 31; ++j) {
            if (s[i] & 1LL << j) sb[i][j] = sb[i-1][j] + 1;
            else sb[i][j] = sb[i-1][j];
        }
    }

    ll ans = 0;
    for (int i = 0; i <= n - 2; ++i) {
        for (int j = 0; j < 31; ++j) {
            ll count = sb[n][j] - sb[i+1][j];
            if (s[i] & 1LL << j) {
                ans += (n - i - 1 - count) * (1LL << j);
            } else {
                ans += count * (1LL << j);
            }
        }
    }

    cout << ans << endl;

    return 0;
}