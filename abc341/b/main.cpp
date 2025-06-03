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
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<ll> s(n-1), t(n-1);
    for (int i = 0; i < n-1; ++i) {
        cin >> s[i] >> t[i];
    }

    for (int i = 0; i < n-1; ++i) {
        ll q = a[i] / s[i];
        a[i+1] += q * t[i];
    }
    cout << a[n-1] << endl;

    return 0;
}