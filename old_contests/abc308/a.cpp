#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> s(8);
    for (int i = 0; i < 8; i++)
    {
        cin >> s[i];
    }

    int prev = -1;
    for (int i = 0; i < 8; i++)
    {
        if (prev > s[i] || s[i] < 100 || s[i] > 675 || s[i] % 25 != 0) {
            cout << "No" << endl;
            return 0;
        }

        prev = s[i];
    }
    
    cout << "Yes" << endl;

    return 0;
}