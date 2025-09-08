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
    int n, nq;
    cin >> n >> nq;
    vector<ll> s(n+1);
    for (int i = 0; i < n; ++i) {
        cin >> s[i+1];
    }
    sort(s.begin(), s.end());
    for (int i = 0; i < n; ++i) {
        s[i+1] += s[i];
    }

    while (nq--) {
        ll x;
        cin >> x;
        cout << upper_bound(s.begin(), s.end(), x) - s.begin() - 1 << endl;
    }

    return 0;
}