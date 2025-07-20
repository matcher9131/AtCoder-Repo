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
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll = long long;

constexpr ll INF = 1LL << 60;

void changeMin(ll& x, ll y) {
    if (y < x) x = y;
}

int main() {
    int n;
    cin >> n;
    // 1-indexed
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    // 行動1を行うときのdp
    // dp1[i][j]: 行動iまでをするかどうかが決まっていて、行動iをj回するときの合計費用の最小値
    // iは1-indexed
    vector<vector<ll>> dp1(n + 1, vector<ll>(2, INF));
    dp1[1][1] = a[1];
    for (int i = 2; i <= n; ++i) {
        // 行動i-1をしていれば行動iをする必要はない
        dp1[i][0] = dp1[i - 1][1];
        
        dp1[i][1] = min(dp1[i - 1][0], dp1[i - 1][1]) + a[i];
    }
    // 行動Nはしてもしなくてもよい
    ll answer1 = min(dp1[n][0], dp1[n][1]);

    // 行動1を行わないときのdp
    vector<vector<ll>> dp0(n + 1, vector<ll>(2, INF));
    dp0[1][0] = 0;
    for (int i = 2; i <= n; ++i) {
        // 行動i-1をしていれば行動iをする必要はない
        dp0[i][0] = dp0[i - 1][1];
        
        dp0[i][1] = min(dp0[i - 1][0], dp0[i - 1][1]) + a[i];
    }
    // 行動Nはしなければならない
    ll answer0 = dp0[n][1];

    cout << min(answer0, answer1) << endl;

    return 0;
}