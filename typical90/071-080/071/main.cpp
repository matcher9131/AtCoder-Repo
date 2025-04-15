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

struct Topological {
    vector<int> result; // ソート結果
    vector<int> candidates; // 次の頂点候補
    vector<int> inDeg; // 各頂点の入次数
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> g(n);
    vector<int> inDeg(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        ++inDeg[b];
    }

    vector<int> source;
    for (int i = 0; i < n; ++i) {
        if (inDeg[i] == 0) source.push_back(i);
    }

    vector<Topological> ans;
    ans.emplace_back(vector<int>(), source, inDeg);

    for (int i = 0; i < k; ++i) {
        if (i >= (int)ans.size()) break;

        while (!ans[i].candidates.empty()) {
            for (int j = 1; j < (int)ans[i].candidates.size() && (int)ans.size() < k; ++j) {
                int from = *(ans[i].candidates.end() - (j + 1));
                vector<int> newResult(ans[i].result);
                vector<int> newCandidates(ans[i].candidates);
                vector<int> newInDeg(ans[i].inDeg);
                newResult.push_back(from);
                newCandidates.erase(newCandidates.end() - (j + 1));
                for (const int to : g[from]) {
                    --newInDeg[to];
                    if (newInDeg[to] == 0) {
                        newCandidates.push_back(to);
                    }
                }
                ans.emplace_back(newResult, newCandidates, newInDeg);
            }

            int from = ans[i].candidates.back();
            ans[i].result.push_back(from);
            ans[i].candidates.pop_back();
            for (const int to : g[from]) {
                --ans[i].inDeg[to];
                if (ans[i].inDeg[to] == 0) {
                    ans[i].candidates.push_back(to);
                }
            }
        }
    }

    if (count_if(ans.begin(), ans.end(), [&](Topological &x) {
        return (int)x.result.size() == n;
    }) >= k) {
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << ans[i].result[j] + 1 << " \n"[j == n - 1];
            }
        }
    } else {
        cout << -1 << endl;
    }

    return 0;
}