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

    int suc = 1;
    for (int i = 1; i < n; ++i) {
        if (p[i] > p[i - 1]) {
            ++suc;
            if (suc >= k) {
                display(p);
                return 0;
            }
        } else {
            suc = 1;
        }
    }

    int i = n - k;
    vector<int> q = p;
    sort(q.end() - k, q.end());
    while (i > 0 && q[i - 1] < q[i]) --i;
    sort(p.begin() + i, p.begin() + i + k);
    display(p);

    return 0;
}