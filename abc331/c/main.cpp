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
    vector<int> b = a;
    sort(b.begin(), b.end());
    vector<ll> s(n+1);
    for (int i = 0; i < n; ++i) {
        s[i+1] = s[i] + b[i];
    }

    for (int i = 0; i < n; ++i) {
        int j = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
        cout << s[n] - s[j] << " \n"[i == n - 1];
    }

    return 0;
}