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
using namespace std;
using ll = long long;


int main() {
    int m;
    cin >> m;
    vector<int> d(m);
    int s = 0;
    for (int i = 0; i < m; ++i) {
        cin >> d[i];
        s += d[i];
    }

    int middle = s / 2;
    for (int i = 0; i < m; ++i) {
        if (middle < d[i]) {
            cout << i + 1 << " " << middle + 1 << endl;
            return 0;
        } else {
            middle -= d[i];
        }
    }
    
    return 0;
}