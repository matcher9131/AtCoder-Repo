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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ll ans = 0;
    int right = 0;
    int sum = 0;
    for (int left = 0; left < n; ++left) {
        while (right < n && (sum & a[right]) == 0) {
            sum |= a[right];
            ++right;
        }

        ans += ((ll)(right - left) + (right - left + 1)) / 2;

        if (right == left) {
            ++right;
        } else {
            sum ^= a[left];
        }
    }

    cout << ans << endl;
    return 0;
}