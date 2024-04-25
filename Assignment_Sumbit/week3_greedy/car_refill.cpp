#include <iostream>
#include <vector>

using namespace std;

int compute_min_refills(int dist, int tank, vector<int>& stops) {
    int total_refills = 0;
    int current_refill = 0;

    int last_refill = 0;
    int n = stops.size();
    while (current_refill < n - 1)
    {
        last_refill = current_refill;
        while (current_refill < n - 1 && stops[current_refill + 1] - stops[last_refill] < tank)
        {
            current_refill++;
        }

        if (last_refill == current_refill)
        {
            return -1;
        }

        if (current_refill < n - 1)
        {
            total_refills++;
        }
    }
    if (dist - stops[current_refill] <= tank)
    {
        return total_refills;
    }
    return -1;
}

int main() {
    int d, m, n;
    cin >> d >> m >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops[i];

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
