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
    vector<pair<int, string>> s(n);
    for (int i = 0; i < n; ++i) {
        string si;
        cin >> si;
        s[i] = { (int)si.size(), si };
    }
    sort(s.begin(), s.end());

    for (int i = 0; i < n; ++i) {
        cout << s[i].second;
    }
    cout << endl;

    return 0;
}