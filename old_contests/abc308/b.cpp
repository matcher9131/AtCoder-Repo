#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> c(n);
    vector<string> d(m);
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> d[i];
    }
    int p0;
    cin >> p0;
    vector<int> p(m);
    for (int i = 0; i < m; i++)
    {
        cin >> p[i];
    }
    
    int s = 0;
    for (const auto &dish : c)
    {
        auto itr = find(d.begin(), d.end(), dish);
        if (itr == d.end()) {
            s += p0;
        } else {
            s += p[itr - d.begin()];
        }
    }
    
    cout << s << endl;

    
    return 0;
}