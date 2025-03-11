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
    int n;
    string s, t;
    cin >> n >> s >> t;
    s += "..";
    t += "..";

    unordered_map<string, int> dist;
    queue<string> que;

    dist[s] = 0;
    que.push(s);

    while (!que.empty()) {
        string current = que.front();
        que.pop();

        if (current == t) {
            cout << dist[current] << endl;
            return 0;
        }

        int blank = current.find('.');
        for (int i = 0; i <= n; ++i) {
            if (i == blank || i == blank + 1 || current[i + 1] == '.') continue;
            string next = current;
            swap(next[i], next[blank]);
            swap(next[i + 1], next[blank + 1]);
            if (dist.contains(next)) continue;
            dist[next] = dist[current] + 1;
            que.push(next);
        }
    }

    cout << -1 << endl;

    return 0;
}