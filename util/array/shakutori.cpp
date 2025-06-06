#include <vector>

extern int n;
extern int x;
extern std::vector<int> a;

auto shakutori = [&]() {
    int right = 0;
    int sum = 0;
    for (int left = 0; left < n; ++left) {
        while (right < n && sum + a[right] <= x) {
            sum += a[right];
            ++right;
        }

        /* some code here */

        if (right == left) {
            ++right;
        } else {
            sum -= a[left];
        }
    }
};

