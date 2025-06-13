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
#include <atcoder/segtree>
using namespace std;
using ll = long long;

constexpr ll INF = 1e18;
using S1 = ll;
S1 op1(S1 a, S1 b) {
    return min(a, b);
}
S1 e1() {
    return INF;
}

using S2 = ll;
S2 op2(S2 a, S2 b) {
    return max(a, b);
}
S2 e2() {
    return 0;
}



int main() {
    int n, z, w;
    cin >> n >> z >> w;
    vector<ll> a(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    auto getScore = [&](int i, int j) {
        ll x = i == 0 ? z : a[i];
        ll y = j == 0 ? w : a[j];
        return abs(x - y);
    };

    vector<atcoder::segtree<S1, op1, e1>> segRow(n+1, atcoder::segtree<S1, op1, e1>(n+1));
    vector<atcoder::segtree<S2, op2, e2>> segCol(n+1, atcoder::segtree<S2, op2, e2>(n+1));
    
    for (int i = n; i >= 0; --i) {
        for (int j = n; j >= 0; --j) {
            if (i > 0 && i == j) continue;
            if (i == n || j == n) {
                segRow[i].set(j, getScore(i, j));
                segCol[j].set(i, getScore(i, j));
            } else if (i > j) {
                // dp[i][i+1:n+1]で最小のもの
                ll val = segRow[i].prod(i+1, n+1);
                segRow[i].set(j, val);
                segCol[j].set(i, val);
            } else {
                // dp[j+1:n+1][j]で最大のもの
                ll val = segCol[j].prod(j+1, n+1);
                segRow[i].set(j, val);
                segCol[j].set(i, val);
            }
        }
    }
    
    cout << segRow[0].get(0) << endl;

    return 0;
}