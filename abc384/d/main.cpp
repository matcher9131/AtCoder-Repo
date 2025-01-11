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
    ll s;
    cin >> n >> s;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ll cycleSum = accumulate(a.begin(), a.end(), 0LL);
    s %= cycleSum;

    int r = 0;
    ll sum = 0;
    for (int l = 0; l < 2 * n; ++l) {
        while (r < 2 * n && sum + a[r % n] <= s) {
            sum += a[r % n];
            ++r;
        }
        if (sum == s) {
            cout << "Yes" << endl;
            return 0;
        }

        if (r == l) {
            ++r;
        } else {
            sum -= a[l % n];
        }
        if (sum == s) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    if (sum == s) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}