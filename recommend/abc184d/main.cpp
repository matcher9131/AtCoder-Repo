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
using namespace std;
using ll = long long;


int main() {
    int a, b, c;
    cin >> a >> b >> c;
    vector<vector<vector<double>>> dp(101, vector<vector<double>>(101, vector<double>(101)));

    for (int i = 99; i >= a; --i) {
        for (int j = 99; j >= b; --j) {
            for (int k = 99; k >= c; --k) {
                double n = i + j + k;
                dp[i][j][k] += (dp[i + 1][j][k] + 1) * i / n + (dp[i][j + 1][k] + 1) * j / n + (dp[i][j][k + 1] + 1) * k / n; 
            }
        }
    }

    cout << setprecision(15) << dp[a][b][c] << endl;

    return 0;
}