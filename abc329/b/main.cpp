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
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ll max = *max_element(a.begin(), a.end());
    for (ll i = 0; i < n; ++i) {
        if (a[i] == max) {
            a[i] = 0;
        }
    }

    cout << *max_element(a.begin(), a.end()) << endl;

    return 0;
}