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
    string s;
    cin >> n >> s;
    vector<vector<int>> charIndices(26);
    for (int i = 0; i < n; ++i) {
        charIndices[s[i] - 'a'].push_back(i);
    }

    vector<int> charDst(26);
    for (int i = 0; i < 26; ++i) {
        charDst[i] = i;
    }
    int nq;
    cin >> nq;
    while (nq--) {
        char c, d;
        cin >> c >> d;
        for (int i = 0; i < 26; ++i) {
            if (charDst[i] == c - 'a') {
                charDst[i] = d - 'a';
            }
        }
    }

    for (int ci = 0; ci < 26; ++ci) {
        for (const int index : charIndices[ci]) {
            s[index] = (char)('a' + charDst[ci]);
        }
    }

    cout << s << endl;
    return 0;
}