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
using namespace std;
using ll = long long;


int main() {
    int n;
    cin >> n;
    // s, f
    vector<pair<ll, ll>> x(n);
    for (int i = 0; i < n; ++i) {
        ll f, s;
        cin >> f >> s;
        x[i] = make_pair(s, f);
    }
    sort(x.begin(), x.end(), greater<pair<int, int>>());

    if (x[0].second == x[1].second) {
        ll same = x[0].first + x[1].first / 2;
        for (int i = 2; i < n; ++i) {
            if (x[i].second != x[0].second) {
                ll dif = x[0].first + x[i].first;
                cout << max(same, dif) << endl;
                return 0;
            }
        }
        cout << same << endl;
    } else {
        cout << x[0].first + x[1].first << endl;
    }
    
    return 0;
}