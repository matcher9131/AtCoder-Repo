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
    int n, d;
    cin >> n >> d;
    vector<double> w(n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }
    sort(w.begin(), w.end(), greater<double>());
    double avg = accumulate(w.begin(), w.end(), 0.0) / d;

    priority_queue<pair<double, double>> bags;
    for (int i = 0; i < d; ++i) {
        bags.emplace(avg * avg, 0);
    }
    vector<double> bagsFinished;
    
    for (int i = 0; i < n; ++i) {
        auto [pd, sum] = bags.top();
        bags.pop();
        if (sum + w[i] > avg) {
            bagsFinished.push_back(sum + w[i]);
        } else {
            double ns = sum + w[i];
            bags.emplace((ns - avg) * (ns - avg), ns);
        }
    }
    while (!bags.empty()) {
        auto [_, sum] = bags.top();
        bags.pop();
        bagsFinished.push_back(sum);
    }

    double ans = 0;
    for (int i = 0; i < d; ++i) {
        printf("bag[%d] = %lf\n", i, bagsFinished[i]);
        ans += (bagsFinished[i] - avg) * (bagsFinished[i] - avg);
    }
    ans /= d;

    cout << setprecision(15) << ans << endl;
    return 0;
}