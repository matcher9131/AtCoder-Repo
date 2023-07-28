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
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> d(m);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        d[i] = make_pair(a, b);
    }
    sort(d.begin(), d.end(), [](const auto &a, const auto &b) {
        return a.second < b.second;
    });

    int answer = 0;
    int prevLast = 0;
    for (int i = 0; i < m; ++i) {
        if (d[i].first >= prevLast) {
            ++answer;
            prevLast = d[i].second;
        }
    }
    
    cout << answer << endl;

    return 0;
}