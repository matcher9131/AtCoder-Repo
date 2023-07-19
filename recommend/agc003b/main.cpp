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
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll = long long;


int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ll count = 0;
    for (int i = 0; i < n; ++i) {
        count += a[i] / 2;
        a[i] %= 2;
        if (a[i] == 1 && i < n - 1 && a[i + 1] > 0) {
            ++count;
            --a[i + 1];
        }
    }

    cout << count << endl;

    return 0;
}