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
    int n, t;
    cin >> n >> t;
    vector<ll> a(t), b(t);
    for (int i = 0; i < t; ++i) {
        cin >> a[i] >> b[i];
        --a[i];
    }

    vector<ll> score(n);
    map<ll, int> scoreCount;
    scoreCount[0] = n;

    for (int ti = 0; ti < t; ++ti) {
        ll oldScore = score[a[ti]];
        ll newScore = oldScore + b[ti];
        score[a[ti]] = newScore;
        --scoreCount[oldScore];
        if (scoreCount[oldScore] == 0) {
            scoreCount.erase(oldScore);
        }
        ++scoreCount[newScore];
        cout << scoreCount.size() << endl;
    }

    return 0;
}