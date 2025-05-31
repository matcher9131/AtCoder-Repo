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
    int n, s;
    cin >> n >> s;
    vector<int> t(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }

    int last = 0;
    for (int i = 0; i < n; ++i) {
        if (last + s < t[i]) {
            cout << "No" << endl;
            return 0;
        }
        last = t[i];
    }

    cout << "Yes" << endl;
    return 0;
}