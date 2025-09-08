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
    vector<vector<int>> dices(n, vector<int>());
    int rollMax = 0;
    for (int i = 0; i < n; ++i) {
        int ki;
        cin >> ki;
        for (int j = 0; j < ki; ++j) {
            int aij;
            cin >> aij;
            dices[i].push_back(aij);
            rollMax = max(rollMax, aij);
        }
    }

    vector<vector<double>> prob(n, vector<double>(rollMax + 1));
    for (int i = 0; i < n; ++i) {
        double p = 1.0 / dices[i].size();
        for (const int roll : dices[i]) {
            prob[i][roll] += p;
        }
    }

    double ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            double pMeet = 0;
            for (int roll = 1; roll <= rollMax; ++roll) {
                pMeet += prob[i][roll] * prob[j][roll];
            }
            ans = max(ans, pMeet);
        }
    }

    cout << setprecision(15) << ans << endl;

    return 0;
}