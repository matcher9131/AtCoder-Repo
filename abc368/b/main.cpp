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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int ans = 0;
    while (true) {
        int np = count_if(a.begin(), a.end(), [](int n) {return n > 0;});
        if (np <= 1) break;

        sort(a.begin(), a.end(), greater<int>());
        --a[0];
        --a[1];
        ++ans;
    }

    cout << ans << endl;

    return 0;
}