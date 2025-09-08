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
    string s;
    cin >> s;
    ll n = s.size();

    ll hold = -1;
    for (ll i = 0; i < n; ++i) {
        if (s[i] == '#') {
            if (hold >= 0) {
                cout << hold+1 << "," << i+1 << endl;
                hold = -1;
            } else {
                hold = i;
            }
        }
    }

    return 0;
}