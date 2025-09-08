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
    string s, t;
    cin >> s >> t;
    transform(s.begin(), s.end(), s.begin(), ::toupper);

    int first = s.find(t[0]);
    if (first == string::npos) {
        cout << "No" << endl;
        return 0;
    }

    int second = s.find(t[1], first + 1);
    if (second == string::npos) {
        cout << "No" << endl;
        return 0;
    }

    if (t[2] == 'X') {
        cout << "Yes" << endl;
    } else {
        int third = s.find(t[2], second + 1);
        cout << (third == string::npos ? "No" : "Yes") << endl;
    }

    return 0;
}