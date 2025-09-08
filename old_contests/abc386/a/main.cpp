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
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int arr[13] = {};
    ++arr[a-1];
    ++arr[b-1];
    ++arr[c-1];
    ++arr[d-1];

    bool two = false;
    for (const int n : arr) {
        if (n == 3) {
            cout << "Yes" << endl;
            return 0;
        } else if (n == 2) {
            if (two) {
                cout << "Yes" << endl;
                return 0;
            } else {
                two = true;
            }
        }
    }

    cout << "No" << endl;
    return 0;
}