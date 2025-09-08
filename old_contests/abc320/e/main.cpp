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
    int n, m;
    cin >> n >> m;
    vector<ll> t(m), w(m), s(m);
    for (int i = 0; i < m; ++i) {
        cin >> t[i] >> w[i] >> s[i];
    }

    vector<ll> sum(n);
    // <1> = false: 時刻<0>に人<2>が列に戻る
    // <1> = true: 時刻<0>に<2>回目のそうめんが流れてくる
    priority_queue<tuple<ll, bool, int>, vector<tuple<ll, bool, int>>, greater<tuple<ll, bool, int>>> que;
    for (int i = 0; i < m; ++i) {
        que.emplace(t[i], true, i);
    }
    set<int> waiting;
    for (int i = 0; i < n; ++i) {
        waiting.emplace_hint(waiting.end(), i);
    }

    while (!que.empty()) {
        auto [ti, event, j] = que.top();
        que.pop();
        if (event) {
            auto it = waiting.begin();
            if (it == waiting.end()) continue;
            int person = *it;
            sum[person] += w[j];
            que.emplace(t[j] + s[j], false, person);
            waiting.erase(person);
        } else {
            waiting.insert(j);
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << sum[i] << endl;
    }

    return 0;
}