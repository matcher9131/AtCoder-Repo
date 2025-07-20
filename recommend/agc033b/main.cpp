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
    ll h, w, n, pi, pj;
    string s, t;
    cin >> h >> w >> n >> pi >> pj >> s >> t;
    --pi;
    --pj;

    ll l = 0, r = w-1, u = 0, d = h-1;
    for (ll i = n - 1; i >= 0; --i) {
        // 左右
        if (i != n-1) {
            if (t[i] == 'L' && r < w-1) ++r;
            if (t[i] == 'R' && l > 0) --l;   
        }
        if (s[i] == 'L') ++l;
        else if (s[i] == 'R') --r;
        if (l > r) {
            cout << "NO" << endl;
            return 0;
        }
        // 上下
        if (i != n-1) {
            if (t[i] == 'U' && d < h-1) ++d;
            if (t[i] == 'D' && u > 0) --u;
        }
        if (s[i] == 'U') ++u;
        else if (s[i] == 'D') --d;
        if (u > d) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << (l <= pj && pj <= r && u <= pi && pi <= d ? "YES" : "NO") << endl;
    return 0;
}