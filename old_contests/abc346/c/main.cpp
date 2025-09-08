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
    ll n, k;
    cin >> n >> k;
    set<ll> exists;
    for (int i = 0; i < n; ++i) {
        ll ai;
        cin >> ai;
        if (ai <= k) {
            exists.insert(ai);
        }
    }

    ll sumExists = accumulate(exists.begin(), exists.end(), 0LL);
    cout << k * (k+1) / 2 - sumExists << endl;

    return 0;
}