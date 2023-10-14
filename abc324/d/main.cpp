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

bool sequence_equal(vector<int> &x, vector<int> &y) {
    if (x.size() != y.size()) return false;
    for (int i = 0; i < x.size(); ++i) {
        if (x[i] != y[i]) return false;
    }
    return true;
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> count(10);
    for (int i = 0; i < n; ++i) {
        ++count[s[i] - '0'];
    }

    ll ans = 0;
    for (ll i = 0LL; i <= (ll)sqrt(pow(10, n)); ++i) {
        ll sqr = i * i;
        vector<int> d(10);
        for (int j = 0; j < n; ++j) {
            ++d[sqr % 10];
            sqr /= 10;
        }
        if (sequence_equal(count, d)) ++ans;
    }

    cout << ans << endl;

    return 0;
}