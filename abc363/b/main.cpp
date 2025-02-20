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
    int n, t, p;
    cin >> n >> t >> p;
    vector<int> l(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i];
    }

    for (int d = 0; d <= 100; ++d) {
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (l[i] >= t) ++count;
            ++l[i];
        }
        if (count >= p) {
            cout << d << endl;
            return 0;
        }
    }

   return 0;
}