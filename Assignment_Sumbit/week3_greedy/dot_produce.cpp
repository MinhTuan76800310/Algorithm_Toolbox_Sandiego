#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define ll long long

void merge(vector<int>& arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1);
    vector<int> R(n2);

    // copy value to L and R 
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++)
    {
        R[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] > R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

}

void MergeSort(vector<int>& arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

long long max_dot_product(vector<int> a, vector<int> b) {
    // write your code here
    long long result = 0;
    MergeSort(a, 0, a.size() - 1);
    MergeSort(b, 0, b.size() - 1);
    for (size_t i = 0; i < a.size(); i++) {
        result += ((long long)a[i]) * b[i];
    }
    return result;
}

int main() {
    size_t n;
    cin >> n;
    vector<int> a(n), b(n);
    for (size_t i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (size_t i = 0; i < n; i++) {
        cin >> b[i];
    }
    cout << max_dot_product(a, b) << endl;
}
