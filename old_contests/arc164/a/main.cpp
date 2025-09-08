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

bool solve(ll n, ll k) {
    if (n < k || n % 2 != k % 2) return false;
    int sumPlaces = 0;
    for (ll q = n; q > 0; q /= 3) {
        sumPlaces += q % 3;
    }
    return sumPlaces <= k;
}

int main() {
    int t;
    cin >> t;
    vector<ll> n(t);
    vector<ll> k(t);
    for (int i = 0; i < t; ++i) {
        cin >> n[i] >> k[i];
    }
    for (int i = 0; i < t; ++i) {
        cout << (solve(n[i], k[i]) ? "Yes" : "No") << endl;
    }


    return 0;
}