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


int h, w;
 
int main() {
    int n;
    cin >> h >> w >> n;
    vector<vector<bool>> hole(h, vector<bool>(w));
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        hole[a][b] = true;
    }
 
    vector<vector<int>> rd(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
        rd[i][0] = hole[i][0] ? 0 : 1;
    }
    for (int j = 0; j < w; ++j) {
        rd[0][j] = hole[0][j] ? 0 : 1;
    }
 
    for (int i = 1; i < h; ++i) {
        for (int j = 1; j < w; ++j) {
            rd[i][j] = hole[i][j] ? 0 : min(min(rd[i - 1][j - 1], rd[i - 1][j]), rd[i][j - 1]) + 1;
        }
    }
 
    ll count = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            count += rd[i][j];
        }
    }
 
    cout << count << endl;
 
    return 0;
}