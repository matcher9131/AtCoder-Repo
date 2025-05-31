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
    for (int i = 0; i < n; ++i) {
        bool isFirst = true;
        for (int j = 0; j < n; ++j) {
            int aij;
            cin >> aij;
            if (aij == 1) {
                cout << (isFirst ? "" : " ") << j+1;
                isFirst = false;
            }
        }
        cout << endl;
    }

    return 0;
}