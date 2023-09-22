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
    int n, l, k;
    cin >> n >> l >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    auto isOK = [&](int x) {
        int left = 0;
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (count < k && a[i] - left >= x){
                ++count;
                left = a[i];
            }
        }
        return count == k && l - left >= x;
    };

    auto binary_search = [&]() {
        int ng = l;
        int ok = 0;

        while (abs(ok - ng) > 1) {
            int mid = (ok + ng) / 2;
            if (isOK(mid)) ok = mid;
            else ng = mid;
        }

        return ok;
    };

    cout << binary_search() << endl;

    return 0;
}