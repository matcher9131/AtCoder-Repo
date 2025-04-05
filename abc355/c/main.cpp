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
    int n, t;
    cin >> n >> t;
    vector<int> a(t);
    for (int i = 0; i < t; ++i) {
        cin >> a[i];
        --a[i];
    }

    vector<int> rows(n);
    vector<int> cols(n);
    int diagur = 0, diaglr = 0;

    for (int i = 0; i < t; ++i) {
        int r = a[i] / n, c = a[i] % n;
        ++rows[r];
        if (rows[r] == n) {
            cout << i + 1 << endl;
            return 0;
        }
        ++cols[c];
        if (cols[c] == n) {
            cout << i + 1 << endl;
            return 0;
        }
        if (r == c) {
            ++diaglr;
            if (diaglr == n) {
                cout << i + 1 << endl;
                return 0;
            }
        }
        if (r + c == n - 1) {
            ++diagur;
            if (diagur == n) {
                cout << i + 1 << endl;
                return 0;
            }
        }
    }

    cout << -1 << endl;

    return 0;
}