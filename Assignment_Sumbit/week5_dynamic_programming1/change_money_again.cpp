#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

vector<int> denomination = { 1, 3, 4 };

int min_3_value(int a, int b, int c)
{
    return min(min(a, b), c);
}

int get_change(int m)
{
    vector<int> min_no_coin(m + 1);
    min_no_coin[0] = 0;

    for (int i = 1; i <= m; i++)
    {
        min_no_coin[i] = INT_MAX;
        for (int j = 0; j < 3; j++)
        {
            if (i >= denomination[j])
            {
                min_no_coin[i] = min(min_no_coin[i], min_no_coin[i - denomination[j]] + 1);
            }
        }
    }

    return min_no_coin[m];
}

int main() {
    int m;
    std::cin >> m;
    std::cout << get_change(m) << '\n';
    return 0;
}
