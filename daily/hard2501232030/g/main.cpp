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

    int zero = 0, one = n - 1;
    while (abs(zero - one) > 1) {
        int mid = (zero + one) / 2;
        cout << "? " << mid + 1 << endl;
        int si;
        cin >> si;
        if (si == 1) one = mid;
        else zero = mid;
    }

    cout << "! " << zero + 1 << endl;

    return 0;
}