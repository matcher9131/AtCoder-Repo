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
    int n, k;
    cin >> n >> k;

    vector<int> p(n+1);
    for (int d = 2; d <= n; ++d) {
        if (p[d] > 0) continue;
        for (int i = d; i <= n; i += d) {
            ++p[i];
        }
    }

    cout << count_if(p.begin(), p.end(), [&](int x) { return x >= k; }) << endl;
    return 0;
}