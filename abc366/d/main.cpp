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
    vector<vector<vector<ll>>> a(n, vector<vector<ll>>(n, vector<ll>(n)));
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < n; ++y) {
            for (int z = 0; z < n; ++z) {
                cin >> a[x][y][z];
            }
        }
    }

    vector<vector<vector<ll>>> s(n + 1, vector<vector<ll>>(n + 1, vector<ll>(n + 1)));
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < n; ++y) {
            for (int z = 0; z < n; ++z) {
                s[x+1][y+1][z+1] = s[x+1][y+1][z] + s[x][y+1][z+1] + s[x+1][y][z+1] - s[x+1][y][z] - s[x][y+1][z] - s[x][y][z+1] + s[x][y][z] + a[x][y][z];
            }
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int x1, x2, y1, y2, z1, z2;
        cin >> x1 >> x2 >> y1 >> y2 >> z1 >> z2;
        --x1; --y1; --z1;
        cout << s[x2][y2][z2] - s[x1][y2][z2] - s[x2][y1][z2] - s[x2][y2][z1] + s[x2][y1][z1] + s[x1][y2][z1] + s[x1][y1][z2] - s[x1][y1][z1] << endl;
    }

    return 0;
}