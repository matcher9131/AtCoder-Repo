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
    ll n, nq;
    cin >> n >> nq;
    vector<unordered_set<int>> box(n);
    for (ll i = 0; i < n; ++i) {
        ll ci;
        cin >> ci;
        --ci;
        box[i].insert(ci);
    }
    
    while (nq--) {
        ll a, b;
        cin >> a >> b;
        --a;
        --b;
        if (box[a].size() >= box[b].size()) swap(box[a], box[b]);
        for (const int c : box[a]) {
            box[b].insert(c);
        }
        box[a].clear();
        cout << box[b].size() << endl;
    }

    return 0;
}