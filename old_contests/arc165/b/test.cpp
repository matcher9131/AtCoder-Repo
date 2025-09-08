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

void display(const vector<int>& v) {
    if (!v.empty()) cout << v[0];
    for (int i = 1; i < v.size(); ++i) {
        cout << " " << v[i];
    }
    cout << endl;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    vector<int> q = p;
    sort(q.end() - k, q.end());
    for (int i = 0; i < n - k; ++i) {
        vector<int> t = p;
        sort(t.begin() + i, t.begin() + i + k);
        if (t > q) q = t;
    }
    display(q);

    return 0;
}