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
    int n, m;
    cin >> n >> m;
    vector<int> s(n+1);
    for (int i = 0; i < m; ++i) {
        int li, ri;
        cin >> li >> ri;
        --li;
        ++s[li];
        --s[ri];
    }

    for (int i = 1; i <= n; ++i) {
        s[i] += s[i-1];
    }

    cout << *min_element(s.begin(), s.begin() + n) << endl;

    return 0;
}