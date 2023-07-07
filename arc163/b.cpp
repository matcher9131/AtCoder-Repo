#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;
using int64 = long long;

int main() {
    int n, m;
    cin >> n >> m;
    int64 a1, a2;
    cin >> a1 >> a2;
    vector<int64> a(n - 2);
    for (int i = 0; i < n - 2; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    
    int64 minCount = LLONG_MAX;
    for (int i = 0; i <= n - m - 2; i++)
    {
        int64 c = (a1 > a[i] ? a1 - a[i] : 0) + (a2 < a[i + m - 1] ? a[i + m - 1] - a2 : 0);
        minCount = min(minCount, c);
    }

    cout << minCount << endl;

    return 0;
}