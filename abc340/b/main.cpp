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
    int nq;
    cin >> nq;
    vector<int> a;

    while (nq--) {
        int k, x;
        cin >> k >> x;
        if (k == 1) {
            a.push_back(x);
        } else {
            cout << a[(int)a.size() - x] << endl;
        }
    }

    return 0;
}