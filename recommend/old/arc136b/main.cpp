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
    vector<int> a(n), b(n);
    vector<int> numA(5001), numB(5001);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++numA[a[i]];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        ++numB[b[i]];
    }

    bool dup = false;
    for (int i = 1; i <= 5000; ++i) {
        if (numA[i] != numB[i]) {
            cout << "No" << endl;
            return 0;
        }
        if (numA[i] > 1) dup = true;
    }
    
    if (dup) {
        cout << "Yes" << endl;
        return 0;
    }

    int aInv = 0, bInv = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (a[i] > a[j]) ++aInv;
            if (b[i] > b[j]) ++bInv;
        }
    }

    cout << (aInv % 2 == bInv % 2 ? "Yes" : "No") << endl;
    return 0;
}