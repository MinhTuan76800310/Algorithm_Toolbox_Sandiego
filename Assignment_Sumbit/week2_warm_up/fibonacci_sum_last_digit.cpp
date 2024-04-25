#include <iostream>

using namespace std;

#define ll long long

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current = 1;
    long long sum = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

ll fibonacci_sum_fast(ll n)
{
    if (n <= 1)
        return n;

    ll previous_1 = 0, previous_2 = 1, recent_value, sum = 1;
    for (ll i = 2; i <= n; i++)
    {
        recent_value = (previous_1 + previous_2) % 10;
        sum += recent_value;
        sum = sum % 10;
        previous_1 = previous_2;
        previous_2 = recent_value;
    }
    return sum;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_fast(n);
}
