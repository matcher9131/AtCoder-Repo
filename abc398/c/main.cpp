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
    map<int, vector<int>> m;
    for (int i = 0; i < n; ++i) {
        int ai;
        cin >> ai;
        m[ai].push_back(i);
    }

    for (auto it = m.rbegin(); it != m.rend(); ++it) {
        if (it->second.size() == 1) {
            cout << it->second[0] + 1 << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}