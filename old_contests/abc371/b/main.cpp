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
    int n, m;
    cin >> n >> m;
    vector<bool> t(n);
    for (int i = 0; i < m; ++i) {
        int a;
        char b;
        cin >> a >> b;
        --a;
        if (b == 'M' && !t[a]) {
            cout << "Yes" << endl;
            t[a] = true;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}