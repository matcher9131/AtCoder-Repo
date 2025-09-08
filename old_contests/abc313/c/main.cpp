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
using namespace std;
using ll = long long;


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    ll s = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        s += a[i];
    }
 
    ll lower = s / n;
    ll upper = (s + n - 1) / n;
 
    ll increment = 0, decrement = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] >= upper) decrement += a[i] - upper;
        else increment += lower - a[i];
    }
 
    cout << max(increment, decrement) << endl;
 
    return 0;
}