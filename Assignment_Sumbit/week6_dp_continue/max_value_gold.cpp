#include <iostream>
#include <vector>

using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int findPivotIndex(vector<int>& arr, int l, int r, int idx_val) {
    int less_iter = l;
    int greater_iter = r;
    int iter_arr = l;
    int pivot_val = arr[idx_val];
    while (iter_arr <= greater_iter) {
        if (arr[iter_arr] < pivot_val) {
            swap(arr[iter_arr], arr[less_iter]);
            less_iter++;
            iter_arr++;
        }
        else if (arr[iter_arr] > pivot_val) {
            swap(arr[iter_arr], arr[greater_iter]);
            greater_iter--;
        }
        else {
            iter_arr++;
        }
    }
    swap(arr[idx_val], arr[greater_iter]);
    return greater_iter;
}

void quickSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int mid = l + (r - l) / 2;
        int pivot = findPivotIndex(arr, l, r, mid);
        quickSort(arr, l, pivot - 1);
        quickSort(arr, pivot + 1, r);
    }
}

int optimal_weight(int W, const vector<int>& w) {
    // Sao chép vector w vào w_t
    vector<int> w_t = w;
    int row = w_t.size();
    int col = W + 1;
    quickSort(w_t, 0, w_t.size() - 1);
    vector<vector<int>> gold_value(row + 1, vector<int>(col));

    for (int i = 0; i <= row; i++) {
        for (int j = 0; j < col; j++) {
            if (i == 0 || j == 0) {
                gold_value[i][j] = 0;
            }
            else if (j >= w_t[i - 1]) {
                gold_value[i][j] = max(w_t[i - 1] + gold_value[i - 1][j - w_t[i - 1]], gold_value[i - 1][j]);
            }
            else {
                gold_value[i][j] = gold_value[i - 1][j];
            }
        }
    }
    return gold_value[row][W];
}

int main() {
    int n, W;
    cin >> W >> n;
    vector<int> w(n);
    for (int i = 0; i < n; i++) { cin >> w[i]; }
    cout << optimal_weight(W, w) << '\n';
    return 0;
}