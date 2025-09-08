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
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        int ai;
        cin >> ai;
        if (ai % k == 0) {
            ans.push_back(ai / k);
        }
    }

    for (int i = 0; i < (int)ans.size(); ++i) {
        cout << ans[i] << " \n"[i == (int)ans.size() - 1];
    }

    return 0;
}