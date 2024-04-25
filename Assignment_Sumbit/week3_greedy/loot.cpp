#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int find_index(vector<int> w, vector<int> v, double value)
{
    int res;
    for (int i = 0; i < w.size(); i++)
    {
        if (value == (double)v[i] / w[i])
        {
            res = i;
        }
    }
    return res;
}

void merge(vector<double>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<double> L(n1), R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        }
        else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }
    while (j < n2) {
        arr[k++] = R[j++];
    }
}

void mergeSort(vector<double>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}


double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
    double value = 0.0;
    // write your code here
    if (capacity > accumulate(weights.begin(), weights.end(), 0)) {
        return accumulate(values.begin(), values.end(), 0);
    }
    int m = values.size();
    vector<double> vpw(m);

    for (int i = 0; i < m; i++)
    {
        vpw[i] = (double)values[i] / weights[i] * 1.0;
    }

    // Sort
    mergeSort(vpw, 0, vpw.size() - 1);
    int index = vpw.size() - 1;

    int tmp_index;
    while (capacity > 0 && index >= -1)
    {
        tmp_index = find_index(weights, values, vpw[index]);
        if (capacity > weights[tmp_index])
        {
            capacity = capacity - weights[tmp_index];
            value = value + values[tmp_index];
            index--;
        }
        else
        {
            value = value + (double)capacity * vpw[index];
            capacity = 0;
        }
    }
    return value;
}

int main() {
    int n;
    int capacity;
    cin >> n >> capacity;
    vector<int> values(n);
    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        cin >> values[i] >> weights[i];
    }

    double optimal_value = get_optimal_value(capacity, weights, values);

    cout.precision(10);
    cout << optimal_value << std::endl;
    return 0;
}
