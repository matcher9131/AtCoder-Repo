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
    vector<int> c(101);
    for (int i = 0; i < n; ++i) {
        int ai;
        cin >> ai;
        if (ai <= 100) {
            ++c[ai];
        } else {
            ++c[100];
        }
    }
    
    for (int i = 99; i >= 0; --i) {
        c[i] += c[i+1];
    }

    int ans = 0;
    for (int i = 0; i <= 100; ++i) {
        if (c[i] >= i) {
            ans = i;
        }
    }

    cout << ans << endl;

    return 0;
}