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
    ll n, m;
    cin >> n >> m;

    ll x = 0;
    for (int i = 0; i <= m; ++i) {
        ll t = 1;
        for (int j = 0; j < i; ++j) {
            t *= n;
            if (t > 1e9) {
                cout << "inf" << endl;
                return 0;
            }
        }
        x += t;
        if (x > 1e9) {
            cout << "inf" << endl;
            return 0;
        }
    }

    cout << x << endl;

    return 0;
}