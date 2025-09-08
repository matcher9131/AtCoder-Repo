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
    cin >> n;
    map<int, pair<int, int>> list;
    list[0] = { 0, 0 };
    for (int i = 0; i < n; ++i) {
        int ai;
        cin >> ai;
        int prev = list[0].first;
        list[prev].second = ai;
        list[ai] = { prev, 0 };
        list[0].first = ai;
    }

    int nq;
    cin >> nq;
    while (nq--) {
        int k;
        cin >> k;
        if (k == 1) {
            int x, y;
            cin >> x >> y;
            int z = list[x].second;
            list[x].second = y;
            list[y] = { x, z };
            list[z].first = y;
        } else {
            int x;
            cin >> x;
            auto [u, v] = list[x];
            list[u].second = v;
            list[v].first = u;
            list.erase(x);
        }
    }

    int prev = 0;
    while (true) {
        int current = list[prev].second;
        if (current == 0) {
            cout << endl;
            break;
        }
        cout << (prev != 0 ? " " : "") << current;
        prev = current;
    }

    return 0;
}