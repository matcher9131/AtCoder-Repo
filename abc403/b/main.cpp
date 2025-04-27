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
    string t, u;
    cin >> t >> u;
    int n = t.size();
    int m = u.size();

    for (int i = 0; i < n - m + 1; ++i) {
        bool ok = true;
        for (int j = 0; j < m; ++j) {
            if (t[i+j] != '?' && t[i+j] != u[j]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    
    cout << "No" << endl;
    return 0;
}