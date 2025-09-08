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
    string r, c;
    cin >> n >> r >> c;

    

    function<void(vector<vector<int>>&)> dfs = [&](vector<vector<int>> &g) {
        if (g.size() == n) {
            //
        }
        vector<int> perm = { 1, 2, 3 };
        while (perm.size() < n) perm.insert(perm.begin(), 0);
        do {
            if (*find_if(perm.begin(), perm.end(), [](int x) { return x > 0; }) != r[g.size()] - 'A' + 1) continue;
            dfs(g);
        } while (next_permutation(perm.begin(), perm.end()));
    };

    return 0;
}