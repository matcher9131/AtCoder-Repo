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
    int n, d;
    cin >> n >> d;
    vector<int> t(n), l(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i] >> l[i];
    }

    for (int k = 1; k <= d; ++k) {
        vector<int> d(n);
        for (int i = 0; i < n; ++i) {
            d[i] = t[i] * (l[i] + k);
        }
        cout << *max_element(d.begin(), d.end()) << endl;
    }

    return 0;
}