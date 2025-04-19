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
    vector<set<int>> a(m);
    vector<vector<int>> revA(n);
    for (int i = 0; i < m; ++i) {
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int aij;
            cin >> aij;
            --aij;
            a[i].insert(aij);
            revA[aij].push_back(i);
        }
    }
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        --b[i];
    }

    int ans = 0;
    for (const int bi : b) {
        for (const int mi : revA[bi]) {
            a[mi].erase(bi);
            if (a[mi].empty()) {
                ++ans;
            }
        }
        cout << ans << endl;
    }

    return 0;
}