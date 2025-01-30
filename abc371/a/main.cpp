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
    string sab, sac, sbc;
    cin >> sab >> sac >> sbc;
    if (sab == "<") {
        if (sbc == "<") {
            cout << "B" << endl;
        } else if (sac == ">") {
            cout << "A" << endl;
        } else {
            cout << "C" << endl;
        }
    } else {
        if (sac == "<") {
            cout << "A" << endl;
        } else if (sbc == ">") {
            cout << "B" << endl;
        } else {
            cout << "C" << endl;
        }
    }

    return 0;
}