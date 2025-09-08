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

constexpr ll INF = 1e16;

inline bool exists(int state, int i, int j) {
    return state & (1 << (3 * i + j));
}

int main() {
    vector<vector<ll>> a(3, vector<ll>(3));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> a[i][j];
        }
    }

    unordered_map<int, ll> dp;

    auto riichi = [](int state, int otherState) -> pair<int, int> {
        for (int i = 0; i < 3; ++i) {
            if (exists(state, i, 1) && exists(state, i, 2) && !exists(otherState, i, 0)) return { i, 0 };
            if (exists(state, i, 2) && exists(state, i, 0) && !exists(otherState, i, 1)) return { i, 1 };
            if (exists(state, i, 0) && exists(state, i, 1) && !exists(otherState, i, 2)) return { i, 2 };
        }
        for (int j = 0; j < 3; ++j) {
            if (exists(state, 1, j) && exists(state, 2, j) && !exists(otherState, 0, j)) return { 0, j };
            if (exists(state, 2, j) && exists(state, 0, j) && !exists(otherState, 1, j)) return { 1, j };
            if (exists(state, 0, j) && exists(state, 1, j) && !exists(otherState, 2, j)) return { 2, j };
        }
        if (exists(state, 1, 1) && exists(state, 2, 2) && !exists(otherState, 0, 0)) return { 0, 0 };
        if (exists(state, 2, 2) && exists(state, 0, 0) && !exists(otherState, 1, 1)) return { 1, 1 };
        if (exists(state, 0, 0) && exists(state, 1, 1) && !exists(otherState, 2, 2)) return { 2, 2 };
        if (exists(state, 1, 1) && exists(state, 2, 0) && !exists(otherState, 0, 2)) return { 0, 2 };
        if (exists(state, 2, 0) && exists(state, 0, 2) && !exists(otherState, 1, 1)) return { 1, 1 };
        if (exists(state, 0, 2) && exists(state, 1, 1) && !exists(otherState, 2, 0)) return { 2, 0 };
        return { -1, -1 };
    };

    function<ll(int,int,int)> dfs = [&](int turn, int redState, int blueState) -> ll {
        int state = redState | (blueState << 9);
        if (dp.contains(state)) return dp[state];

        if ((redState | blueState) == 0b111111111) return 0;

        if ((turn == 1 ? riichi(redState, blueState) : riichi(blueState, redState)).first != -1) {
            return dp[state] = INF;
        }
        auto [ri, rj] = turn == -1 ? riichi(redState, blueState) : riichi(blueState, redState);
        if (ri != -1) {
            int newRedState = turn == 1 ? redState | (1 << (3 * ri + rj)) : redState;
            int newBlueState = turn == -1 ? blueState | (1 << (3 * ri + rj)) : blueState;
            ll score = -dfs(-turn, newRedState, newBlueState);
            return dp[state] = score + a[ri][rj];
        }

        ll result = -1e18;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (redState & (1 << (3 * i + j))) continue;
                if (blueState & (1 << (3 * i + j))) continue;
                int newRedState = turn == 1 ? redState | (1 << (3 * i + j)) : redState;
                int newBlueState = turn == -1 ? blueState | (1 << (3 * i + j)) : blueState;
                ll score = -dfs(-turn, newRedState, newBlueState);
                result = max(result, score + a[i][j]);
            }
        }
        return dp[state] = result;
    };

    ll result = dfs(1, 0, 0);
    cout << (result > 0 ? "Takahashi" : "Aoki") << endl;

    return 0;
}
