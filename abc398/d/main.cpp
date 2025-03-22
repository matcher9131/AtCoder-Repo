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
    int n, r, c;
    string s;
    cin >> n >> r >> c >> s;

    set<pair<int, int>> smoke;
    int oi = 0, oj = 0;
    smoke.emplace(0, 0);
    for (int t = 0; t < n; ++t) {
        if (s[t] == 'N') --oi;
        else if (s[t] == 'S') ++oi;
        else if (s[t] == 'E') ++oj;
        else if (s[t] == 'W') --oj;
        smoke.emplace(-oi, -oj);
        cout << (smoke.find({r - oi, c - oj}) != smoke.end());
    }
    cout << endl;

    return 0;
}