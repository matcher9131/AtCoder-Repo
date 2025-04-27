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
    int n, m, nq;
    cin >> n >> m >> nq;

    unordered_map<int, set<int>> map(n);
    unordered_set<int> all;

    while (nq--) {
        int k;
        cin >> k;
        if (k == 1) {
            int x, y;
            cin >> x >> y;
            --x; --y;
            map[x].insert(y);
        } else if (k == 2) {
            int x;
            cin >> x;
            --x;
            all.insert(x);
        } else {
            int x, y;
            cin >> x >> y;
            --x; --y;
            if (all.contains(x) || map[x].contains(y)) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }

    return 0;
}