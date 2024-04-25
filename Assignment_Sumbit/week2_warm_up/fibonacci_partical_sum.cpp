#include <iostream>
#include <vector>

using namespace std;
using std::vector;

#define ll long long

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
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

ll fibonacci_last_digit(ll n)
{
    ll res = 0;
    ll minus_1 = 1;
    ll minus_2 = 0;
    ll current;
    for (ll i = 2; i <= n; i++)
    {
        current = (minus_2 + minus_1) % 10;
        minus_2 = minus_1;
        minus_1 = current;
    }
    return current;
}

ll get_fibonacci_partial_sum_fast(ll from, ll to)
{
    ll sum_from = fibonacci_last_digit(from);
    ll sum_end = fibonacci_last_digit(to);
    if (sum_from > sum_end)
    {
        return sum_end + (10 - sum_from);
    }
    if (from == to)
    {
        return sum_end;
    }
    return sum_end - sum_from;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}