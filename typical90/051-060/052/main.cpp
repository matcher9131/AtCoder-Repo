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
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint1000000007;


int main() {
    int n;
    cin >> n;
    mint ans = 1;
    for (int i = 0; i < n; ++i) {
        mint s = 0;
        for (int j = 0; j < 6; ++j) {
            int aij;
            cin >> aij;
            s += aij;
        }
        ans *= s;
    }

    cout << ans.val() << endl;

    return 0;
}