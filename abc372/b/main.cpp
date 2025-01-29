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
    int m;
    cin >> m;
    vector<int> a;
    
    for (int i = 0; ; ++i) {
        if (m == 0) break;
        int k = m % 3;
        for (int kk = 0; kk < k; ++kk) {
            a.push_back(i);
        }
        m /= 3;
    }

    cout << a.size() << endl;
    for (int i = 0; i < a.size(); ++i) {
        cout << a[i] << " \n"[i == a.size() - 1];
    }

    return 0;
}