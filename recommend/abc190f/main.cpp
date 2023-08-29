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
using namespace std;
using ll = long long;

class BIT {
    int _n;
    vector<int> _bit;

public:
    BIT(int n) : _n(n + 1), _bit(_n) {}
    void add(int index, int x) {
        for (int i = index; i < _n; i += (i & -i)) {
            _bit[i] += x;
        }
    }
    ll sum(int index) {
        ll s = 0;
        for (int i = index; i > 0; i -= (i & -i)) {
            s += _bit[i];
        }
        return s;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    BIT bit(n);
    ll answer = 0;
    for (int i = 0; i < n; ++i) {
        answer += i - bit.sum(a[i]);
        bit.add(a[i] + 1, 1);
    }
    cout << answer << endl;

    for (int i = 0; i < n - 1; ++i) {
        answer += n - 1 - 2 * a[i];
        cout << answer << endl;
    }

    return 0;
}