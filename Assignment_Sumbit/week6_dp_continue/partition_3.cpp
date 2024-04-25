#include <iostream>
#include <vector>

using std::vector;
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int partition3(vector<int>& A) {
    //write your code here
    int sum_T = 0;
    for (int i = 0; i < A.size(); i++)
    {
        sum_T += A.at(i);
    }

    // check error
    if ((sum_T % 3) != 0)
    {
        return 0;
    }
    if (A.size() < 3)
    {
        return 0;
    }

    vector<int> A_T;
    A_T = A;
    quickSort(A_T, 0, A_T.size() - 1);

    vector<bool> check(sum_T + 1, false);
    check.at(0) = true;

    int target1 = sum_T / 3;
    int target2 = target1 * 2;
    for (int i = 0; i < A_T.size(); i++)
    {
        for (int j = target2; j >= A_T.at(i); j--)
        {
            if ((check.at(j - A_T.at(i))) == true)
            {
                check.at(j) = true;
            }
        }
    }

    int res = 10;
    if (check.at(target2) == true && check.at(target1) == true)
    {
        res = 1;
    }
    else
    {
        res = 0;
    }
    return res;
}

int main()
{
    int n;
    std::cin >> n;
    vector<int> A(n);
    for (size_t i = 0; i < A.size(); ++i) {
        std::cin >> A[i];
    }
    std::cout << partition3(A) << '\n';
}
