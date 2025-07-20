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
    ll n, d;
    cin >> n >> d;

    if (n * d > n * (n-1) / 2) {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
    for (ll di = 1; di <= d; ++di) {
        for (ll i = 0; i < n; ++i) {
            cout << i+1 << " " << (i+di)%n + 1 << endl;
        }
    }

    return 0;
}