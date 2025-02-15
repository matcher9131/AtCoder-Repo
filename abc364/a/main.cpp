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
    bool isSweet = false;
    string s;
    while (n--) {
        cin >> s;
        if (s == "sweet") {
            if (isSweet && n > 0) {
                cout << "No" << endl;
                return 0;
            } else {
                isSweet = true;
            }
        } else {
            isSweet = false;
        }
    }

    cout << "Yes" << endl;

    return 0;
}