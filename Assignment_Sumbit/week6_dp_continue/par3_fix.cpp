#include <iostream>
#include <vector>
#include <algorithm> 

using std::vector;
using namespace std;

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
    int sum_T = 0;
    for (int i = 0; i < A.size(); i++) {
        sum_T += A.at(i);
    }

    if ((sum_T % 3) != 0 || A.size() < 3) { 
        return 0;
    }

    vector<int> A_T;
    A_T = A;
    sort(A_T.begin(), A_T.end()); 

    vector<bool> check(sum_T + 1, false);
    check.at(0) = true;

    int target1 = sum_T / 3;
    int target2 = target1 * 2;
    for (int i = 0; i < A_T.size(); i++) {
        for (int j = target2; j >= A_T.at(i); j--) {
            if ((check.at(j - A_T.at(i))) == true) {
                check.at(j) = true;
            }
        }
    }

    if (check.at(target2) == true && check.at(target1) == true) {
        return 1; 
    }
    else {
        return 0; 
    }
}

int main() {
    int n;
    std::cin >> n;
    vector<int> A(n);
    for (size_t i = 0; i < A.size(); ++i) {
        std::cin >> A[i];
    }
    std::cout << partition3(A) << '\n'; 
}
