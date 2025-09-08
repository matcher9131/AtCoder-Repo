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
    int n;
    cin >> n;
    vector<int> w(n), x(n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i] >> x[i];
    }

    vector<int> t(24);
    for (int i = 0; i < n; ++i) {
        for (int j = 9; j < 18; ++j) {
            t[(x[i] + j) % 24] += w[i];
        }
    }

    cout << *max_element(t.begin(), t.end()) << endl;

    return 0;
}