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
using namespace std;
using ll = long long;

int n, m;
vector<string> s;
set<string> used;

void create(string current, int i, int extra) {
    if (i == n) {
        if (used.find(current) == used.end() && current.size() >= 3) {
            cout << current << endl;
            exit(0);
        }
        return;
    }
    
    for (int ex = 0; ex <= extra; ++ex) {
        string next = current;
        for (int i = 0; i < ex; ++i) {
            next += "_";
        }
        next += "_" + s[i];
        create(next, i + 1, extra - ex);
    }
}

int main() {
    cin >> n >> m;
    s = vector<string>(n);
    int extra = 16 - (n - 1);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        extra -= s[i].size();
    }
    for (int j = 0; j < m; ++j) {
        string t;
        cin >> t;
        used.insert(t);
    }
    sort(s.begin(), s.end());

    do {
        create(s[0], 1, extra);
    } while (next_permutation(s.begin(), s.end()));

    cout << -1 << endl;

    return 0;
}