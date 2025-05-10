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
    int n = s.size();

    set<string> t;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            t.insert(s.substr(i, j-i));
        }
    }

    cout << t.size() << endl;
    return 0;
}