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
    vector<int> t(n), v(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i] >> v[i];
    }

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            sum = max(0, sum - (t[i] - t[i - 1]));
        }
        sum += v[i];
    }

    cout << sum << endl;

    return 0;
}