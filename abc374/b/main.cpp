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
    string s, t;
    cin >> s >> t;

    int n = min(s.size(), t.size());
    for (int i = 0; i < n; ++i) {
        if (s[i] != t[i]) {
            cout << i + 1 << endl;
            return 0;
        }
    }

    cout << (s.size() == t.size() ? 0 : n + 1) << endl;

    return 0;
}