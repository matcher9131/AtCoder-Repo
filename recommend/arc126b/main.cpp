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
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> lines(m);
    for (int i = 0; i < m; ++i) {
        int ai, bi;
        cin >> ai >> bi;
        lines[i] = { ai, bi };
    }
    sort(lines.begin(), lines.end(), [](auto a, auto b) {
        return a.first == b.first ? a.second > b.second : a.first < b.first;
    });

    vector<int> lis;
    for (const auto& [_, bi] : lines) {
        auto dst = lower_bound(lis.begin(), lis.end(), bi);
        if (dst == lis.end()) {
            lis.push_back(bi);
        } else {
            *dst = bi;
        }
    }
    
    cout << lis.size() << endl;
    return 0;
}