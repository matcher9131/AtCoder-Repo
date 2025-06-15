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
    int n, t, m;
    cin >> n >> t >> m;
    vector<unsigned> ng(m);
    for (int i = 0; i < m; ++i) {
        int ai, bi;
        cin >> ai >> bi;
        --ai;
        --bi;
        ng[i] = (1U << ai) | (1U << bi);
    }

    auto isOK = [&](unsigned pattern) {
        for (int i = 0; i < m; ++i) {
            if ((pattern & ng[i]) == ng[i]) return false;
        }
        return true;
    };

    ll ans = 0;
    function<void(int, vector<unsigned>&)> dfs = [&](int i, vector<unsigned> &team) {
        if (i == n) {
            if (all_of(team.begin(), team.end(), [](unsigned val) { return val > 0; })) ++ans;
            return;
        }
        bool last = false;
        for (int j = 0; j < t; ++j) {
            if (team[j] == 0) {
                team[j] = 1U << i;
                last = true;
                dfs(i+1, team);
                team[j] = 0;
            } else {
                if (isOK(team[j] | (1U << i))) {
                    team[j] |= 1U << i;
                    dfs(i+1, team);
                    team[j] ^= 1U << i;
                }
            }
            if (last) break;
        }
    };
    vector<unsigned> team(t);
    dfs(0, team);

    cout << ans << endl;
    return 0;
}