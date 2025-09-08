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
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> d(n);
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
        --d[i];
        d[i] %= (a+b);
    }
    sort(d.begin(), d.end());

    if (d.back() <= d[0] + a - 1) {
        cout << "Yes" << endl;
        return 0;
    }
    for (int i = 0; i < n - 1; ++i) {
        if (d[i+1] - d[i] > b) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}