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

int getNext(int i) {
    int t = i;
    while (i > 0) {
        t += i % 10;
        i /= 10;
    }
    return t % 100000;
}

int main() {
    int n;
    ll k;
    cin >> n >> k;

    int m = 1e5;
    vector<int> next(m);
    for (int i = 0; i < m; ++i) {
        next[i] = getNext(i);
    }

    vector<bool> visited(m);
    vector<int> history;
    int cycleRoot = -1;
    function<void(int, ll)> dfs = [&](int from, ll count) {
        if (count == k) {
            cout << from << endl;
            exit(0);
        }

        visited[from] = true;
        history.push_back(from);
        int to = next[from];
        if (visited[to]) {
            cycleRoot = to;
            return;
        }
        dfs(to, count + 1);
        if (cycleRoot != -1) return;
    };
    dfs(n, 0);

    int cycleBegin = find(history.begin(), history.end(), cycleRoot) - history.begin();
    int cycleLength = history.size() - cycleBegin;

    cout << history[(k - cycleBegin) % cycleLength + cycleBegin] << endl;

    return 0;
}