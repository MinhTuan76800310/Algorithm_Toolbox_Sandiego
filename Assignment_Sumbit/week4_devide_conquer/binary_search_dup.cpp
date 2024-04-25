#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

int binary_search(const vector<int>& a, int x) {
    int left = 0, right = (int)a.size() - 1; // Corrected the initialization of right
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] == x) {
            // Find the leftmost occurrence of x
            while (mid > 0 && a[mid] == a[mid - 1]) {
                mid--;
            }
            return mid;
        }
        else if (a[mid] > x) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return -1;
}

int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); i++) {
        std::cin >> a[i];
    }
    int m;
    std::cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> b[i];
    }
    for (int i = 0; i < m; ++i) {
        std::cout << binary_search(a, b[i]) << ' ';
    }
    return 0;
}
