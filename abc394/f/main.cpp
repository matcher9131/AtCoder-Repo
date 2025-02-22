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
#include <atcoder/dsu>
using namespace std;
using ll = long long;
using dsu = atcoder::dsu;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> g(n, vector<int>());
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int ans = 0;
    // dp[i]: 頂点iおよびその子孫のうちアルキル基として使える頂点数の最大値
    vector<int> dp(n);
    function<void(int,int)> dfs = [&](int from, int parent) -> void {
        dp[from] = 1;
        vector<int> dpc;
        for (const int to : g[from]) {
            if (to == parent) continue;
            dfs(to, from);
            dpc.push_back(dp[to]);
        }
        sort(dpc.begin(), dpc.end(), greater<int>());

        // fromが水素原子のパターン
        if (!dpc.empty()) {
            ans = max(ans, dpc[0] + 1);
        }
        // fromが炭素原子のパターン
        if (dpc.size() >= 4) {
            ans = max(ans, dpc[0] + dpc[1] + dpc[2] + dpc[3] + 1);
        }
        // アルキル基の大きさを更新
        if (dpc.size() >= 3) {
            dp[from] = dpc[0] + dpc[1] + dpc[2] + 1;
        }
    };
    dfs(0, -1);

    cout << (ans < 5 ? -1 : ans) << endl;


    return 0;
}