#include <iostream>
#include <vector>

using namespace std;

#define ll long long

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}


ll get_fibonacci_fast(ll n, ll m)
{
    if (n <= 1)
        return n;

    ll previous_1 = 0, previous_2 = 1, recent_value;
    for (ll i = 2; i <= n; i++)
    {
        recent_value = (previous_1 + previous_2) % m;
        previous_1 = previous_2;
        previous_2 = recent_value;
    }
    return recent_value;
}
int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_fast(n, m) << '\n';
}
