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
    string s;
    cin >> s;
    if (s == "ACE" || s == "BDF" || s == "CEG" || s == "DFA" || s == "EGB" || s == "FAC" || s == "GBD") {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}