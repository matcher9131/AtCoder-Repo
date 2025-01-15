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
    vector<ll> a(2 * n);
    ll x = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[n + i] = a[i];
        x += a[i];
    }
    if (x % 10 != 0) {
        cout << "No" << endl;
        return 0;
    }
    x /= 10;

    int right = 0;
    ll sum = 0;
    for (int left = 0; left < 2 * n; ++left) {
        while (right < 2 * n && sum + a[right] <= x) {
            sum += a[right];
            ++right;
        }

        if (sum == x) {
            cout << "Yes" << endl;
            return 0;
        }

        if (right == left) {
            ++right;
        } else {
            sum -= a[left];
        }
    }

    cout << "No" << endl;
    return 0;
}