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
    string ss;
    cin >> ss;

    unordered_map<string, unordered_set<string>> g;
    string s = "acdeort";
    do {
        for (int i = 0; i < 6; ++i) {
            string t = s;
            char tmp = t[i + 1];
            t[i + 1] = t[i];
            t[i] = tmp;
            g[s].insert(t);
            g[t].insert(s);
        }
    } while (next_permutation(s.begin(), s.end()));

    unordered_map<string, bool> visited;
    unordered_map<string, int> dist;
    queue<string> que;
    visited[ss] = true;
    dist[ss] = 0;
    que.push(ss);
    while (!que.empty()) {
        string sc = que.front();
        que.pop();
        for (const string& next : g[sc]) {
            if (visited.contains(next)) continue;
            visited[next] = true;
            if (dist.contains(next)) {
                dist[next] = min(dist[next], dist[sc] + 1);
            } else {
                dist[next] = dist[sc] + 1;
            }
            que.push(next);
        }
    }

    cout << dist["atcoder"] << endl;

    return 0;
}