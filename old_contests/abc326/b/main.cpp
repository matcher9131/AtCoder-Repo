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
    for (int i = n; i <= 919; ++i) {
        if ((i / 100) * (i / 10 % 10) == i % 10) {
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}