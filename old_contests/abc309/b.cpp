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
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;
//using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        string t;
        cin >> t;
        for (int j = 0; j < n; j++)
        {
            a[i][j] = (int)(t[j] - '0');
        }
    }
    
    int ur = a[0][n-1];
    for (int i = n - 2; i >= 0; --i)
    {
        a[0][i + 1] = a[0][i];
    }
    int lr = a[n-1][n-1];
    for (int i = n - 2; i >= 1; --i)
    {
        a[i + 1][n - 1] = a[i][n - 1];
    }
    a[1][n-1] = ur;
    int ll = a[n - 1][0];
    for (int i = 0; i < n - 2; ++i)
    {
        a[n - 1][i] = a[n - 1][i + 1];
    }
    a[n-1][n-2] = lr;
    for (int i = 0; i < n - 2; ++i)
    {
        a[i][0] = a[i + 1][0];
    }
    a[n-2][0] = ll;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j];            
        }
        cout << endl;
    }
    

    return 0;
}