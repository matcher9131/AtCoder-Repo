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
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll = long long;

int main() {
    int n, t, m;
    cin >> n >> t >> m;
    vector<vector<bool>> dis(n, vector<bool>(n));
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        dis[a][b] = true;
        dis[b][a] = true;
    }

    

    return 0;
}