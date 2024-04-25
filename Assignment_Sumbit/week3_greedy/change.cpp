#include <iostream>

using namespace std;

int get_change(int m) {
    //write your code here
    int total = 0;
    int tmp = 0;
    while (m > 0)
    {
        tmp = m / 10;
        if (tmp != 0)
        {
            m = m - 10 * tmp;
            total = total + tmp;
        }
        tmp = 0;

        tmp = m / 5;
        if (tmp != 0)
        {
            m = m - 5 * tmp;
            total = total + tmp;
        }
        total = total + m;
        break;
    }
    return total;
}

int main() {
    int m;
    cin >> m;
    cout << get_change(m) << '\n';
}
