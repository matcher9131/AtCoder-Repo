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
    vector<int> a(n), w(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }

    vector<vector<int>> box(n);
    for (int i = 0; i < n; ++i) {
        box[a[i]].push_back(w[i]);
    }

    for (auto& b : box) {
        sort(b.begin(), b.end());
    }

    cout << accumulate(box.begin(), box.end(), 0, [](int acc, vector<int>& b) -> int {
        return acc + (b.size() > 1 ? accumulate(b.begin(), b.end() - 1, 0) : 0);
    }) << endl;

    return 0;
}