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
    vector<string> s(n);
    int sc = 0;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        int ci;
        cin >> ci;
        sc += ci;
    }
    sort(s.begin(), s.end());

    cout << s[sc % n] << endl;

    return 0;
}