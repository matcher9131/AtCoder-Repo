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
    int nq;
    cin >> nq;
    vector<pair<int, int>> q(nq);
    for (int i = 0; i < nq; ++i) {
        int k, x;
        cin >> k;
        if (k != 1) {
            cin >> x;
            q[i] = make_pair(k, x);
        } else {
            q[i] = make_pair(k, 0);
        }
    }

    ll t = 0;
    int numHarvest = 0;
    vector<ll> plants;
    for (const auto& [k, x] : q) {
        if (k == 1) {
            plants.push_back(t);
        } else if (k == 2) {
            t += x;
        } else {
            int newNumHarvest = upper_bound(plants.begin(), plants.end(), t - x) - plants.begin();
            cout << newNumHarvest - numHarvest << endl;
            numHarvest = newNumHarvest;
        }
    }

    return 0;
}