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
    int n, s, m, l;
    cin >> n >> s >> m >> l;

    int lMax = (n + 11) / 12;
    int ans = 1e8;
    for (int i = 0; i <= lMax; ++i) {
        int mMax = max((n - 12*i + 7) / 8, 0);
        for (int j = 0; j <= mMax; ++j) {
            int k = max((n - 12*i - 8*j + 5) / 6, 0);
            ans = min(ans, i*l + j*m + k*s);
        }
    }

    cout << ans << endl;
    return 0;
}